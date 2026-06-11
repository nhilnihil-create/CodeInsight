#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define rep(i, n) for(int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fi first
#define se second
#define pb push_back
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;

string board[6];
int h, w, k;

int check (int H, int W) {
    int cnt = 0;
    rep(i, h) rep(j, w) {
        if ((H >> i) & 1 || (W >> j) & 1 || board[i][j] != '#') continue;
        cnt++;
    }
    return cnt;
}

void solve() {
    cin >> h >> w >> k;
    rep(i, h) cin >> board[i];
    int ans = 0;
    rep(H, 1 << h) rep(W, 1 << w) {
        if (check(H, W) == k) ans++;
    }
    cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}