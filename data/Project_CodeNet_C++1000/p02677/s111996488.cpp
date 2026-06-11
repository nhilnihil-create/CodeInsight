#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;
using pll = pair<ll, ll>;

#define rep(i, n) for (ll i = 0, xxx_rep_end = (n); i < xxx_rep_end; ++i)
#define all(x) (x).begin(), (x).end()

template <class T1, class T2>
inline bool chmax(T1 &a, const T2 &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template <class T1, class T2>
inline bool chmin(T1 &a, const T2 &b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

constexpr ll INF = 0x3f3f3f3f3f3f3f3fLL;
constexpr ll mod = 1000000007;

int main() {
    double a, b, h, m;

    cin >> a >> b >> h >> m;

    double rad = ((h * 30 + m * 0.5) - m * 6) * M_PI / 180.0;

    cout << std::setprecision(50);
    cout << sqrt(a * a + b * b - 2 * a * b * cos(rad)) << endl;
}