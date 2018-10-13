#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <queue>
using namespace std;

int main(int argc, char *argv[])
{
    fstream file;
    string buffer;
    buffer = ".\\"+argv[4]+"\\matrix.data";
    int cou = 0;
    file.open(buffer,ios::in);
    int i,j;
    file>>i>>j;
    long *array = new long[i*j];
    queue<pair<int,int>> slot;
    for(int ii=0;ii<i;ii++){
        for(int jj=0;jj<j;jj++){
            file>>array[ii*j+jj];
        }
    }
    for(int ii=0;ii<i;ii++){
        for(int jj=0;jj<j+1;jj++){
            if(ii!=0&&ii!=i-1){
                if(jj!=0&&jj!=j-1){
                    if(array[ii*j+jj] >= array[ii*j+jj-1] &&
                       array[ii*j+jj] >= array[ii*j+jj+1] &&
                       array[ii*j+jj] >= array[(ii-1)*j+jj] &&
                       array[ii*j+jj] >= array[(ii+1)*j+jj]){
                        cou++;
                        slot.push(make_pair<int,int>(ii+1,jj+1));
                    }
                }else if(jj==0){
                    if(array[ii*j+jj] >= array[ii*j+jj+1] &&
                       array[ii*j+jj] >= array[(ii-1)*j+jj] &&
                       array[ii*j+jj] >= array[(ii+1)*j+jj]){
                        cou++;
                        slot.push(make_pair<int,int>(ii+1,jj+1));
                    }
                }else if(jj==j-1){
                    if(array[ii*j+jj] >= array[ii*j+jj-1] &&
                       array[ii*j+jj] >= array[(ii-1)*j+jj] &&
                       array[ii*j+jj] >= array[(ii+1)*j+jj]){
                        cou++;
                        slot.push(make_pair<int,int>(ii+1,jj+1));
                    }
                }
            }else if(ii==0){
                if(jj!=0&&jj!=j-1){
                    if(array[ii*j+jj] >= array[ii*j+jj-1] &&
                       array[ii*j+jj] >= array[ii*j+jj+1] &&
                       array[ii*j+jj] >= array[(ii+1)*j+jj]){
                        cou++;
                        slot.push(make_pair<int,int>(ii+1,jj+1));
                    }
                }else if(jj==0){
                    if(array[ii*j+jj] >= array[ii*j+jj+1] &&
                       array[ii*j+jj] >= array[(ii+1)*j+jj]){
                        cou++;
                        slot.push(make_pair<int,int>(ii+1,jj+1));
                    }
                }else if(jj==j-1){
                    if(array[ii*j+jj] >= array[ii*j+jj-1] &&
                       array[ii*j+jj] >= array[(ii+1)*j+jj]){
                        cou++;
                        slot.push(make_pair<int,int>(ii+1,jj+1));
                    }
                }
            }else if(ii==i-1){
                if(jj!=0&&jj!=j-1){
                    if(array[ii*j+jj] >= array[ii*j+jj-1] &&
                       array[ii*j+jj] >= array[ii*j+jj+1] &&
                       array[ii*j+jj] >= array[(ii-1)*j+jj]){
                        cou++;
                        slot.push(make_pair<int,int>(ii+1,jj+1));
                    }
                }else if(jj==0){
                    if(array[ii*j+jj] >= array[ii*j+jj+1] &&
                       array[ii*j+jj] >= array[(ii-1)*j+jj]){
                        cou++;
                        slot.push(make_pair<int,int>(ii+1,jj+1));
                    }
                }else if(jj==j-1){
                    if(array[ii*j+jj] >= array[ii*j+jj-1] &&
                       array[ii*j+jj] >= array[(ii-1)*j+jj]){
                        cou++;
                        slot.push(make_pair<int,int>(ii+1,jj+1));
                    }
                }
            }
        }
        fstream file2;
        buffer = ".\\"+argv[4]+"\\final.peak";
        file2.open(buffer,ios::out);
        file2<<cou<<endl;
        while(slot.empty()){
            file2<<slot.front().first<<slot.front().second<<endl;
            slot.pop();
        }
    }
    return 0;
}
