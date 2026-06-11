/*BISMILLAH
THE WHITE WOLF
NO DREAM IS TOO BIG AND NO DREAMER IS TOO SMALL*/

#include<bits/stdc++.h>
using namespace std;

#define io ios_base::sync_with_stdio(false)
#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define vll vector<long long>
#define pb push_back
#define mod  998244353
#define pii pair<int, int>
#define PI 2*acos(0.0)
#define forn(i, n) for(int i = 0; i < n; i++)

ll bigmod()
{
    ll x = 2, p = mod - 2, res = 1;
    while(p)
    {
        if(p&1)
            res = (res * x)%mod;
        x = (x*x)%mod;
        p>>=1;
    }
    return res;
}

int main()
{
    io;
    ll n, s;
    cin>>n>>s;
    vll inp(n);
    for(auto& x: inp)
        cin>>x;
    ll dp[n+1][s+1];
    memset(dp, 0LL, sizeof(dp));
    ll minv = bigmod();
    ll tw = 1, p = n;
    while(p--)
        tw = (tw*2)%mod;
    dp[0][0] = tw;
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<=s; j++)
        {
            dp[i+1][j] = (dp[i+1][j] + dp[i][j])%mod;
            if(inp[i] + j <=s)
                dp[i+1][inp[i] +j] =(dp[i+1][inp[i]+j] + dp[i][j] * minv %mod) %mod;
        }
    }
    cout<<dp[n][s];
    return 0;
}