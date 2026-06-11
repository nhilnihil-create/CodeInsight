#include<bits/stdc++.h>
using namespace std;
#define hackcyborg shresth_walia
#define ll long long int
#define ld long double
#define pb push_back
#define p1 1232
#define mod 998244353
#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
long long binpow(long long a, long long b, long long m=mod) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
int main()
{
   IO
   ll n,s;
   cin>>n>>s;
   ll dp[n+1][s+1];
   memset(dp,0,sizeof(dp));
   ll a[n];
   for(int x=0;x<n;x++)
    cin>>a[x];
    dp[0][0]=1;
    ll g=binpow(2,mod-2);
   for(int x=1;x<=n;x++)
    for(int y=0;y<=s;y++)
   {    if(y>=a[x-1])
       dp[x][y]+=(dp[x-1][y-a[x-1]])*g;
       dp[x][y]%=mod;
       dp[x][y]+=dp[x-1][y];
       dp[x][y]%=mod;
   }
   cout<<(dp[n][s]*binpow(2,n))%mod;
}
