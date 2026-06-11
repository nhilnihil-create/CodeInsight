#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;

long long dp[3000];
int main()
{
    int n,i,sum;
    scanf("%d",&n);

    dp[0]=1;
    for(i=1; i<=n; i++){
        for(int j=3; j<=i; j++){
            dp[i]=(dp[i]+dp[i-j])%mod;
        }
    }

    printf("%lld\n",dp[n]);
}