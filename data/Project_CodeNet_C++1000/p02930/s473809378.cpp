#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
const ll INF = 1LL << 60;
const ll MOD = 1000000007;
template <class T>
bool chmax(T &a, const T &b) {
    return (a < b) ? (a = b, 1) : 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    return (b < a) ? (a = b, 1) : 0;
}
template <class C>
void print(const C &c, std::ostream &os = std::cout) {
    std::copy(std::begin(c), std::end(c), std::ostream_iterator<typename C::value_type>(os, " "));
    os << std::endl;
}

int a[500][500];

void solve(int r, int l, int x) {
    if (r + 1 == l)
        return;
    int m = (r + l) / 2;
    for (int i = r; i < m; ++i) {
        for (int j = m; j < l; ++j) {
            a[i][j] = x;
        }
    }
    solve(r, m, x + 1);
    solve(m, l, x + 1);
}

int main() {
    int n;
    cin >> n;
    solve(0, n, 1);
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}