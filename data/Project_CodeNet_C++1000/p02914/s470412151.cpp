#include <bits/stdc++.h>
using namespace std;
long long a[100001], dp[61];
int main(){
    int n;
    scanf("%d", &n);
    long long sum = 0;
    for(int i=1;i<=n;i++){
        scanf("%lld", &a[i]);
        sum ^= a[i];
    }

    for(int i=60;i>=0;i--){
        if((sum>>i)&1){
            for(int j=1;j<=n;j++){
                if((a[j]>>i)&1) a[j] ^= (1ll<<i);
            }
        }
    }

    long long ans = 0;
    memset(dp, -1, sizeof(dp));
    for(int i=1;i<=n;i++){
        long long tmp = a[i];
        for(int j=60;j>=0;j--){
            if(!((tmp>>j)&1)){
                if(dp[j] != -1) tmp ^= dp[j];
            }
        }
        ans = max(ans, tmp);
        tmp = a[i];
        for(int j=60;j>=0;j--){
            if((tmp>>j)&1){
                if(dp[j] != -1) tmp ^= dp[j];
                else{
                    dp[j] = tmp;
                    break;
                }
            }
        }
    }
    printf("%lld\n", ans + (sum^ans));
}