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
    ll a,b,m;
    cin >> a >> b >> m;
    vector<ll> A(a),B(b);
    ll min_a=INF;
    ll min_b=INF;
    rep(i,a){
        cin >> A[i];
        min_a=min(min_a,A[i]);
    }
    rep(i,b){
        cin >> B[i];
        min_b=min(min_b,B[i]);
    }
    vector<ll> x(m),y(m),c(m);
    ll ans=INF;
    rep(i,m){
        cin >> x[i] >> y[i] >> c[i];
        x[i]--;
        y[i]--;
        ans=min(ans,A[x[i]]+B[y[i]]-c[i]);
    }
    ans=min(ans,min_a+min_b);
    cout << ans << endl;
    return 0;
} 
