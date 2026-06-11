#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    long long n, k, s;

    cin >> n >> k >> s;

    long long a[n];

    if(s == 1){
        for(long long i = 0; i < n; i++){
            if(i < k){
                a[i] = 1;
            }
            else{
                a[i] = 2;
            }
        }

        for(long long i = 0; i < n; i++){
            printf("%lld\n", a[i]);
        }

        return 0;
        
    }

    

    for(long long i = 0; i < n; i++){
        if(i < k){
            a[i] = s;
        }
        else{
            a[i] = s-1;
        }
    }

    for(long long i = 0; i < n; i++){
        printf("%lld\n", a[i]);
    }

    return 0;
}