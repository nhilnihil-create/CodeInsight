#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define rep(i,n) for(ll i=0;i<(n);i++)
#define pll pair<ll,ll>
#define pq priority_queue
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(c,x) distance(c.begin(),lower_bound(all(c),x))
#define ub(c,x) distance(c.begin(),upper_bound(all(c),x))

using namespace std;

template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}

const ll mod=1e9+7;

int main()
{
    string s;
    cin >> s;
    ll n=s.length();
    vector<vector<ll>> dp(n+1,vector<ll>(2));
    dp[0][0]=1;
    for(ll i=0;i<n;i++){
        {//a+b=0
            if(s[i]=='1'){
                dp[i+1][1]=dp[i][1]+dp[i][0];
            }
            else{
                dp[i+1][1]=dp[i][1];
                dp[i+1][0]=dp[i][0];
            }
        }
        {//a+b=1
            if(s[i]=='1'){
                dp[i+1][1]+=(dp[i][1]*2)%mod;
                dp[i+1][1]%=mod;
                dp[i+1][0]+=(dp[i][0]*2)%mod;
                dp[i+1][0]%=mod;
            }
            else{
                dp[i+1][1]+=(dp[i][1]*2)%mod;
                dp[i+1][1]%=mod;
            }
        }
    }
    ll ans=(dp[n][1]+dp[n][0])%mod;
    cout << ans << endl;
    return 0;
} 