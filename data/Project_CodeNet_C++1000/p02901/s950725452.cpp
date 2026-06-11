#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define rep(i, n) for(int i = 0; i < n; i++)
#define REP(i, a, b) for(int i = a; i <= b; i++)
#define all(x) x.begin(), x.end()
#define fi first
#define se second
#define debug(...) cerr<<__LINE__<<" ["<<#__VA_ARGS__<<"]:",debug_out(__VA_ARGS__)
template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec)
{ for (auto v : vec) os << v << ' '; os << '\n'; return os; }
template <typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa)
{ os << '(' << pa.first << ',' << pa.second << ')'; return os; }
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T)
{ cerr << " " << H; debug_out(T...); }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;

int dp[1010][5000];

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> A(m), B(m);
    vector<int> C(m);
    rep(i, m) {
        cin >> A[i] >> B[i];
        int bit = 0;
        rep(_, B[i]) {
            int c;
            cin >> c;
            c--;
            bit |= 1 << c;
        }
        C[i] = bit;
    }
    rep(i, 1010) rep(j, 5000) {
        dp[i][j] = INF;
    }
    dp[0][0] = 0;
    rep(i, m) {
        rep(j, 1 << n) {
            chmin(dp[i + 1][j | C[i]], dp[i][j] + A[i]);
            chmin(dp[i + 1][j], dp[i][j]);
        }
    }
    cout << (dp[m][(1 << n) - 1] == INF ? -1 : dp[m][(1 << n) - 1]) << endl;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
