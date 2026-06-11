#include <bits/stdc++.h>
#define NMAX 2005

using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
ll dp[NMAX];
int main()
{
    ll n;
    cin>>n;
    dp[0]=1;
    for(ll i=3;i<=n;i++){
        for(ll j=i-3;j>=0;j--)
            dp[i]=(dp[i]+dp[j])%MOD;
    }
    cout<<dp[n];
    return 0;
}
