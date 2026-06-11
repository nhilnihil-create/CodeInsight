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

const ll INF=1e18;


int main()
{
    string s;
    ll n;
    cin >>  n >> s;
    ll ans=0;
    vector<vector<ll>> dp(n,vector<ll>(n));
    for(ll i=n-1;i>=0;i--){
        for(ll j=n-1;j>=0;j--){
            
            if(s[i]==s[j]){
                dp[i][j]+=1;
                if(i+1<=n-1 && j+1<=n-1){
                    dp[i][j]+=dp[i+1][j+1];
                }
            }
            ans=max(ans,min(dp[i][j],j-i));
        }
    }
    cout << ans << endl;
    return 0;
} 
