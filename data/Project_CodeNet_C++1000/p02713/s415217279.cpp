#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <math.h>
using namespace std;
long int N;
int eu(int x,int y){
    if(x<y) return eu(y,x);
    int r;
    while((r=x%y)){
        x = y;
        y = r;
    }
    return y;
}
int main(){
    cin >> N;
    long int sum=0;
    for(int a=1;a<=N;a++){
        for(int b =1;b<=N;b++){
            for(int c =1; c<=N;c++){
                sum += eu(a,eu(b,c));
            }
        }
    }
    printf("%ld\n",sum);
}