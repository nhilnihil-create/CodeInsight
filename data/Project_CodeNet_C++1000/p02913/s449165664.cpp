#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using WGraph = vector<vector<pair<int, ll>>>;

template<class T>inline bool chmax(T &a, const T &b) { if (b > a) { a = b; return true; } return false; }
template<class T>inline bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

constexpr int INF = 1e9;
constexpr int MOD = 1e9 + 7;
constexpr long long LINF = 1e18;
constexpr double EPS = 1e-10;
constexpr double PI = M_PI;

std::vector<int> zAlgorithm(const std::string& s) {
    int n = (int)s.size();
    if (n == 0) return {};

    std::vector<int> z(n);
    z[0] = 0;
    for (int i=1, j=0; i<n; ++i) {
        if (i + z[i-j] < j + z[j]) {
            z[i] = z[i-j];
        } else {
            int k = std::max(0, j + z[j] - i);
            while (i + k < n && s[i+k] == s[k]) ++k;
            z[i] = k;
            j = i;
        }
    }
    z[0] = n;

    return z;
}

int solve_i(int i, const string &S) {
    auto z = zAlgorithm(S.substr(i));
    int res = 0;
    for (int j=0; j<(int)z.size(); ++j) chmax(res, min(j, z[j]));
    return res;
}

void solve() {
    int N;
    string S;
    cin >> N >> S;

    int ans = 0;
    for (int i=0; i<N; ++i) chmax(ans, solve_i(i, S));
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}
