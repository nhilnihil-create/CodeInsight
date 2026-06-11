#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define rep(i, n) for(int i = 0; i < n; i++)
#define REP(i, a, b) for(int i = a; a < b; i++);
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fi first
#define se second
#define pb push_back
#define debug(x) cerr << #x << ": " << x << endl
#define debug_vec(v) cerr << #v << ":"; rep(i, v.size()) cerr << " " << v[i]; cerr << endl
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;

void solve() {
    int n, m, x;
    int ans = INF;
    cin >> n >> m >> x;
    int C[12], A[12][12];
    rep(i, n) {
        cin >> C[i];
        rep(j, m) cin >> A[i][j];
    }
    rep(bit, 1 << n) {
        int money = 0;
        vector<int> U(m, 0);
        rep(i, n) {
            if (bit >> i & 1) {
                money += C[i];
                rep(j, m) {
                    U[j] += A[i][j];
                }
            }
        }
        bool f = 1;
        rep(i, m) {
            if (U[i] < x) f = 0;
        }
        if (f) chmin(ans, money);
    }
    cout << (ans == INF ? -1 : ans) << endl;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}

