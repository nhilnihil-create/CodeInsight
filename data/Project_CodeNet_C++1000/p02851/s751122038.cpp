#pragma region Macros
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using WGraph = vector<vector<pair<int, ll>>>;

template<class T>inline bool chmax(T &a, const T &b) { if (b > a) { a = b; return true; } return false; }
template<class T>inline bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

constexpr int dx[4] = {-1, 0, 0, 1}, dy[4] = {0, -1, 1, 0};
constexpr int INF = 1e9;
constexpr long long LINF = 1e18;
constexpr long long MOD = 1e9 + 7;
constexpr double EPS = 1e-10;
constexpr double PI = M_PI;
#pragma endregion

void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n+1);
    for (int i=1; i<n+1; i++) {
        cin >> a.at(i);
    }

    for (int i=2; i<n+1; i++) {
        a.at(i) += a.at(i-1);
    }
    for (int i=0; i<n+1; i++) {
        a.at(i) = (a.at(i) - i) % k;
    }

    ll res = 0;
    map<int, int> mp;
    mp[a.at(0)]++;
    for (int i=1; i<n+1; i++) {
        if (i >= k) mp[a.at(i-k)]--;
        res += mp[a.at(i)];
        mp[a.at(i)]++;
    }

    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}
