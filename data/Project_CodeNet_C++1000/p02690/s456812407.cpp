#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main(){
    long long x;
    cin >> x;

    for(long long i = -1000; i <= 1000; i++){
        for(long long j = -1000; j <= 1000; j++){
            if(i*i*i*i*i-j*j*j*j*j == x){
                printf("%lld %lld\n", i, j);
                return 0;
            }
        }
    }
}