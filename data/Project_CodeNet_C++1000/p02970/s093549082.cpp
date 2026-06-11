#include <iostream>
#include <cstdio>
using namespace std;
 int N,D;
int main(){
    cin >> N >> D;
    int i=1+D;
    int count =0;
    while(1){
        if(i-D<=N&&i+D>=N){
            count++;
            break;
        }else{
            count++;
            i+=1+2*D;
        }
    }
    printf("%d\n",count);
}