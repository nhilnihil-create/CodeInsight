#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    long long x;
    cin >> x;

    for(long long a = -1000; a <= 1000; a++){
        for(long long b = -1000; b <= 1000; b++){
            if(a*a*a*a*a - b*b*b*b*b == x){
                printf("%lld %lld\n", a, b);
                return 0;
            }
        }
    }
}