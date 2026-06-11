#include<bits/stdc++.h>
using ll = long long;
#define ALL(v) (v).begin(),(v).end()
#define REP(i,p,n) for(int i=p;i<(int)(n);++i)
#define rep(i,n) REP(i,0,n)
#define dump(a) (cerr << #a << "=" << (a) << endl)
#define DUMP(list) cout << "{ "; for(auto nth : list){ cout << nth << " "; } cout << "}" << endl;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

using namespace std;
//inline void chmax(ll& a, ll b) {
//    a = max(a, b);
//}
typedef pair<ll, ll> P;
const ll INF = 1e12;
const int MX = 2005;
ll dp[MX][MX];
void yesno(bool b) {
    if (b) {
        cout << "Yes" << endl;
    }     else {
        cout << "No" << endl;
    }

}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    rep(i, n+1) rep(j, n+1) dp[i][j] = -INF;
    dp[0][0] = 0;
    vector<P> p;
    rep(i, n) p.emplace_back(a[i], i);
    sort(p.rbegin(), p.rend());
    rep(i, n) {
        int pi = p[i].second;
        rep(l, i+1) {
//            cout << a[pi] << endl;
            ll r = i-l;
            chmax(dp[i+1][l+1], dp[i][l]+ll(pi-l)*a[pi]);
            chmax(dp[i+1][l], dp[i][l]+ll((n-r-1)-pi)*a[pi]);
        }
    }
    ll ans = 0;
    rep(i, n+1) chmax(ans, dp[n][i]);
    cout << ans << endl;
    return 0;

}