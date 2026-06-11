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

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    x--; y--;
    int cnt[2020] = {0};
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int d = min({j - i, abs(x-i) + 1 + abs(y-j)});
            cnt[d]++;
        }
    }
    for(int i = 1; i < n; i++) {
        cout << cnt[i] << endl;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}