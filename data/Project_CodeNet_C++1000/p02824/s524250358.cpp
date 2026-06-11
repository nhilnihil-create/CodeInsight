#include <bits/stdc++.h>
#define rep(a,n) for (ll a = 0; a < (n); ++a)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<vector<ll> > Graph;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1e18;


int main(){
    ll n,m,v,p;
    cin >> n >> m >> v >> p;
    vector<ll>a(n);
    rep(i,n)cin>>a[i];
    sort(a.rbegin(),a.rend());
    n--;
    ll ans = p;
    vector<ll>rs(n+1,0);
    rep(i,n+1)rs[i]=0;
    for(ll i=p-1;i<=n;i++){
        if(i-1<0)rs[i]=a[i];
        else rs[i]=rs[i-1]+a[i];
    }
    ll mv = m*v;
    for(ll i = p;i<=n;i++){
        if(a[i]+m<a[p-1])continue;
        ll s = m*p;
        s += m*(n-i);
        s += (i-p+1)*(a[i]+m)-rs[i-1];
        if(s>=mv)ans++;
    }
    cout << ans << endl;
    return 0;
}

