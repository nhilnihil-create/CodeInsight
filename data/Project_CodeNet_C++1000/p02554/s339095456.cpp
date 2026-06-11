#include <stdio.h>
#include <math.h>

int main(){
    long long int n;
    long long int ans=10;
    long long int diff1 = 9;
    long long int diff2 = 8;
    long long int diff;
    scanf("%lld",&n);

    for(int i=1; i<n; i++){
        ans *= 10;
        diff1 *= 9;
        diff2 *= 8;
        ans %=   (1000000000+7);
        diff1 %= (1000000000+7);
        diff2 %= (1000000000+7);
    }
    diff = (2*diff1 - diff2+1000000000+7)%(1000000000+7);
    ans = ans - diff + 1000000000+7;
    ans %= (1000000000+7);
    printf("%lld",ans);
    return 0;
}