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
#define debug(x) cerr << #x << ": " << x << endl
#define debug_vec(v) cerr << #v << ":"; rep(i, v.size()) cerr << " " << v[i]; cerr << endl
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> P(n), C(n);
    rep(i, n) cin >> P[i], P[i]--;
    rep(i, n) cin >> C[i];

    ll ans = -LINF;

    rep(i, n) {
        int v = i, cnt = 0;
        ll sum = 0;

        do {
            cnt++;
            sum += C[v];
            v = P[v];
        } while(v != i);

        ll x = 0;
        int h = 0;

        do {
            v = P[v];
            x += C[v];
            h++;
            if (h > k) break;
            int m = (k - h) / cnt;
            chmax(ans, max(0LL, sum) * m + x);
        } while(v != i);
    }
    cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
