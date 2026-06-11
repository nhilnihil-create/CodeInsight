#include "bits/stdc++.h"
using namespace std;
using ll     = long long;
using pii    = pair<int, int>;
using pll    = pair<ll, ll>;
using vi     = vector<int>;
using vl     = vector<ll>;
using vvi    = vector<vi>;
using vvl    = vector<vl>;
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

int main() {
    int n;
    cin >> n;
    vvi edges(n, vi(n));
    function<void(int, int, int)> div = [&](int l, int r, int d) {
        if (r - l <= 1)
            return;
        int mid = (l + r) / 2;
        for (int i = l; i < mid; ++i) {
            for (int j = mid; j < r; ++j) {
                edges[i][j] = d;
            }
        }
        div(l, mid, d + 1);
        div(mid, r, d + 1);
    };
    div(0, n, 1); // [0, n)
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            cout << edges[i][j];
            if (j == n - 1)
                cout << endl;
            else
                cout << " ";
        }
    }
    return 0;
}