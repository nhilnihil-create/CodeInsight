#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1000000000;
const int MOD = MM + 7;
const int MAX = 510000;
#define rep(i, n) for(ll i=0; i<n; i++)
#define Rep(i, j, n) for(ll i=j; i<n; i++)
#define all(vec) vec.begin(), vec.end()
template<class T> inline bool chmin(T& a, T b) {if(a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T& a, T b) {if(a < b) {a = b; return true;} return false;}
const ll INF = 1LL << 60;

int main() {
    int n, m, x; cin >> n >> m >> x;
    ll ans = INF;
    vector<int> c(n);
    vector<vector<int>> a(n, vector<int>(m));
    rep(i, n) {
        cin >> c[i];
        rep(j, m) cin >> a[i][j];
    }
    rep(i, (1<<n)) {
        ll tmp = 0;
        ll sum[m] = {0};
        rep(j, n) {
            if(i & (1<<j)) {
                tmp += c[j];
                rep(k, m) sum[k] += a[j][k];
            }
        }
        bool fl = 0;
        rep(j, m) if(sum[j] < x) fl = 1;
        if(fl) continue;
        chmin(ans, tmp);
    }
    cout << (ans == INF ? -1 : ans) << endl;
}
