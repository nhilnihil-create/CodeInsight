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
    ll n,t;
    cin >> n >> t;
    vector<pll> a(n);
    rep(i,n){
        cin >> a[i].fi >> a[i].se;
    }
    sort(a.begin(),a.end());
    vector<vector<ll>> dp1(n+1,vector<ll>(6000));
    vector<vector<ll>> dp2(n+1,vector<ll>(6000));
    for(ll i=1;i<=n;i++){
        for(ll j=0;j<=t-1;j++){
            dp1[i][j]=max(dp1[i][j],dp1[i-1][j]); //i品目を注文しないとき
            dp2[i][j]=max(dp2[i][j],dp1[i-1][j]+a[i-1].se);
            dp1[i][j+a[i-1].fi]=max(dp1[i][j+a[i-1].fi],dp2[i][j]);
        }
    }
    ll ans=0;
    for(ll i=0;i<=n;i++){
        for(ll j=0;j<=t-1;j++){
            ans=max(dp2[i][j],ans);
        }
    }
    cout << ans << endl;
    return 0;
} 