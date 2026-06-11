#include <iostream>
#include <cstdio>
using namespace std;
int N,L;
int main(){
    cin >> N >> L;
    int sum = 0;
    for(int i =1;i<=N;i++){
            sum +=  L + i -1;
    }  
    if(1-L<=0){
        sum = sum - (L + 1 -1);
    }else if(1-L>=N){
        sum = sum - (L + N -1);
    }
    printf("%d\n",sum);
}