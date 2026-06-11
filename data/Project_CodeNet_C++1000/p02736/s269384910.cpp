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

int lucus(int n, int r) {
    for (int i=0; i<=30; ++i) {
        int nn = (int)((n & (1<<i)) != 0);
        int rr = (int)((r & (1<<i)) != 0);
        if (nn == 0 && rr == 1) return 0;
    }
    return 1;
}

bool check(const vector<int> &v, int N) {
    int sum = 0;
    for (int i=0; i<N; ++i) {
        sum += v[i] * lucus(N-1, i);
        sum %= 2;
    }
    return sum % 2 == 1;
}

void solve() {
    int N;
    cin >> N;
    string s;
    cin >> s;

    vector<int> v(N);
    for (int i=0; i<N; ++i) v[i] = s[i] - '1';
    if (check(v, N)) {
        cout << 1 << '\n';
    } else {
        if (count(v.begin(), v.end(), 1)) {
            cout << 0 << '\n';
        } else {
            for (int &x : v) x /= 2;
            if (check(v, N)) {
                cout << 2 << '\n';
            } else {
                cout << 0 << '\n';
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}
