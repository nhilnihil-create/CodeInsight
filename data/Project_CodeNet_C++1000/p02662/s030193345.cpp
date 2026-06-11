
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define mod 1000000007
#define mod2 1000000000
#define mod1 998244353
#define lol ios_base::sync_with_stdio(false);cin.tie(NULL);
#define all(x) (x).begin(), (x).end()
#define F(i, n) for (ll (i) = 0; (i) < (n); (i)++)
#define pb push_back
#define pf push_front
#define mp make_pair
#define f first
#define ss second
int main()
{
    ll n;cin >> n;
    ll s;cin >> s;
    ll arr[n];
    for(ll i=0;i<n;i++) cin >> arr[i];
    ll dp[n+1][s+1];
    memset(dp,0,sizeof(dp));
    dp[0][0] = 1;
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<=s;j++)
        {
            dp[i+1][j] += 2*dp[i][j];
            dp[i+1][j]%=mod1;
            if(j+arr[i]<=s) {dp[i+1][j+arr[i]]+=dp[i][j];dp[i+1][j+arr[i]]%=mod1;} 
        }
    }
    cout << dp[n][s] << endl;
    
}
    