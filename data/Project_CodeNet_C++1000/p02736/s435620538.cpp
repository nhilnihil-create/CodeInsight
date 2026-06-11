#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = (int)(n - 1); i >= 0; i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
#define get_unique(x) x.erase(unique(all(x)), x.end());
typedef long long ll;
typedef complex<double> Complex;
const int INF = 1e9;
const ll MOD = 998244353;
const ll LINF = 1e18;
template <class T>
bool chmax(T& a, const T& b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T& a, const T& b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
vector<T> make_vec(size_t a) {
    return vector<T>(a);
}
template <class T, class... Ts>
auto make_vec(size_t a, Ts... ts) {
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    bool flg = 0;
    rep(i, n) {
        char c;
        cin >> c;
        a[i] = c - '1';
        flg |= a[i] == 1;
    }
    int x = 0;
    rep(i, n) {
        x ^= (a[i] % 2 * (n - 1 == (i | (n - 1 - i))));
    }
    if (x == 1) {
        cout << 1 << endl;
        return 0;
    }
    if (flg) {
        cout << 0 << endl;
        return 0;
    }
    rep(i, n) a[i] /= 2;
    rep(i, n) {
        x ^= (a[i] * (n - 1 == (i | (n - 1 - i))));
    }
    if (x == 0)
        cout << 0 << endl;
    else
        cout << 2 << endl;
}