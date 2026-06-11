#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define se second
#define fi first
#define rep(i, l, r) for (ll i = (ll)(l); i < (ll)(r); i++)
#define print(v) for (const auto itr : v){cout << itr << ' ';} cout << endl;
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 998244353
#define endl "\n"
#define inf 1e18
using namespace std;
const ll INF = 1e18L + 5;
const ll maxn = 1e6+5, maxn1=2e5+3;
#define MAXN 200005
ll ceel(ll a, ll b)
{
   if (a % b == 0)
       return a / b;
   return a / b + 1;
}
ll modneg(ll a,ll m)
{
    a = a % m;
    if(a<0)
        a=a+m;
    return a;
}
ll powermod(ll x, unsigned ll y, ll p){ ll res = 1; x = x % p; while (y > 0){if (y & 1){res = (res*x) % p;}y = y>>1; x = (x*x) % p;} return res;}
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); };



int main()
{

ll n,i,j,k,a,b,c,d,test,cnt=0,s;
cin>>n>>s;
ll arr[n+5];
rep(i,0,n)
    cin>>arr[i];
ll dp[3005][3005];
memset(dp,0,sizeof dp);
for(i=0;i<n;i++)
{
    dp[i][0]=powermod(2,i,mod);
    for(j=0;j<=s;j++)
    {
        dp[i+1][j]+=dp[i][j]*2; dp[i+1][j]%=mod;
        if(j+arr[i]<=s)
        {
            dp[i+1][j+arr[i]]+=dp[i][j];
            dp[i + 1][j + arr[i]]%=mod;
        }
    }
}
// rep(i,0,n)
// {
//     rep(j,0,s)
//         cout<<dp[i][j]<<" ";
//     cout<<endl;
// }
cout<<dp[n][s];
return 0;
}