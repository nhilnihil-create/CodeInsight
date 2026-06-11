#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define rREP(i,m,n) for(ll i = (m); i >= (n); i--)
#define ALL(c) (c).begin(), (c).end()
#define print(x) cout << (x) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " ";} cout<<endl;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int a,b,m;
    cin >> a >> b >> m;
    int ary[a];
    int bary[b];
    rep(i,a) cin >> ary[i];
    rep(i,b) cin >> bary[i];
    int x[m];
    int y[m];
    int c[m];
    rep(i,m) cin >> x[i] >> y[i] >> c[i];

    int ans = INT_MAX;
    rep(i,m)
    {
        ans = min(ans, ary[--x[i]]+bary[--y[i]]-c[i]);
    }
    sort(ary, ary+a);
    sort(bary, bary+a);
    ans = min(ans, ary[0]+bary[0]);
    cout << ans << endl;
    
    
}


