#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using WGraph = vector<vector<pair<int, ll>>>;

template<class T>inline bool chmax(T &a, const T &b) { if (b > a) { a = b; return true; } return false; }
template<class T>inline bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

constexpr int dx[4] = {-1, 0, 0, 1}, dy[4] = {0, -1, 1, 0};
constexpr int INF = 1e9;
constexpr int MOD = 1e9 + 7;
constexpr long long LINF = 1e18;
constexpr double EPS = 1e-10;
constexpr double PI = M_PI;

void solve() {
    ll n;
    cin >> n;

    if (n == 2) {
        cout << 1 << '\n';
        return;
    }

    vector<ll> res;
    res.push_back(n);
    ll m1 = n-1;
    for (ll i=1; i*i<=m1; ++i) {
        if (m1%i == 0) {
            if (i != 1) res.push_back(i);
            res.push_back(m1/i);
        }
    }
    for (ll i=2; i*i<=n; ++i) {
        if (n%i == 0) {
            ll tmp = n/i;
            while (tmp%i == 0) tmp /= i;
            if ((tmp-1)%i == 0) res.push_back(i);
        }
    }
    sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());
    cout << (int)res.size() << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}
