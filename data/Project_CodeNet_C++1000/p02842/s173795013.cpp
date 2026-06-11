#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    long long n;
    cin >> n;


    for(long long i = 0; i <= 50000; i++){
        long double x = (long double) i;
        long long x2 = (long long) (x * 1.08);

        if(x2 == n){
            printf("%lld\n", i);
            
            return 0;
        }
    }

    printf(":(\n");

    return 0;
}