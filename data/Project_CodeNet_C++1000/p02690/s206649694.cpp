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
    ll X;
    cin >> X;

    ll limit = 400;

    for (ll a = -limit; a < limit; ++a) {
        for (ll b = -limit; b < limit; ++b) {
            if (X == pow(a, 5) - pow(b, 5)) {
                cout << a << " " << b << endl;
                return 0;
            }
        }
    }
    cout << "aaa" << endl;
}