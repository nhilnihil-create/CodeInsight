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

int main()
{
    ll n,m;
    cin >> n >> m;
    vector<ll> a(m),b(m);
    vector<vector<ll>> c(m);
    rep(i,m){
        cin >> a[i] >> b[i];
        rep(j,b[i]){
            ll x;
            cin >> x;
            c[i].push_back(x);
        }
    }
    vector<vector<ll>> dp(m+1,vector<ll>(1<<n,INF));
    dp[m][(1<<n)-1]=0;
    for(ll i=m-1;i>=0;i--){
        for(ll s=0;s<(1<<n);s++){
            ll t=s;
            for(auto x:c[i]){
                t|=(1<<(x-1));
            }
            dp[i][s]=min(dp[i+1][s],dp[i+1][t]+a[i]);
        }
    }
    cout << (dp[0][0]==INF?-1:dp[0][0]) << endl;
    return 0;
} 