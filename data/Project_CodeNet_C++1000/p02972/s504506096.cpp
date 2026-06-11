#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    long long n;
    cin >> n;

    long long a[n+1];
    long long b[n+1];
    for(long long i = 1; i <= n; i++){
        cin >> a[i];
        b[i] = 0;
    }

    
    long long count = 0;

    for(long long i = n; i >= 1; i--){
        long long j = i;
        long long sum = 0;
        while(j <= n){
            sum = sum + b[j];
            j = j + i;
        }
        
        if((sum+a[i])%2 == 1){
            b[i] = 1;
            count++;
        }
    
    }

    printf("%lld\n", count);

    if(count >= 1){
        for(long long i = n; i >= 1; i--){
            if(b[i] == 1){
                printf("%lld ", i);
            }
        }
        printf("\n");
    }

    return 0;
}
