#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    long long n, a, b;

    cin >> n >> a >> b;

    if((b-a) % 2 == 0){
        printf("%lld\n", (b-a)/2);
        return 0;
    }

    if(a-1 <= n-b){
        if(b-a == 1){
            printf("%lld\n", b-1);
        }
        else{
            printf("%lld\n", a + (b-a-1)/2);
        }
    }
    else{
        if(b-a == 1){
            printf("%lld\n", n-a);
        }
        else{
            printf("%lld\n", n-b+1 +(b-a-1)/2);
        }
    }
    return 0;
}