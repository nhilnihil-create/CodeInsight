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
 
const ll INF=1e9+7;

ll dp[5005][5005];

int main(){
    ll n;
    cin >> n;
    string s;
    cin>> s;
    for(ll i=n-1;i>=0;i--){
        for(ll j=n-1;j>=0;j--){
            if(s[i]!=s[j]) dp[i][j]=0;
            else dp[i][j]=dp[i+1][j+1]+1;
        }
    }
    ll ans=0;
    rep(i,n){
        rep(j,n){
            if(j<=i) continue;
            ll now=min(dp[i][j],j-i);
            ans=max(ans,now);
        }
    }
    cout << ans << endl;
    return 0;
}