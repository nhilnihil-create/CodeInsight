#include "bits/stdc++.h"
using namespace std;
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

//#define int long long
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rrep(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define all(c) begin(c), end(c)
const int INF =
    sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = 1'000'000'007;
template <class T>
bool chmax(T& a, const T& b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
bool chmin(T& a, const T& b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

template <typename T>
vector<T> gen_v(size_t a) {
    return vector<T>(a);
}
template <typename T, typename... Ts>
auto gen_v(size_t a, Ts... ts) {
    return vector<decltype(gen_v<T>(ts...))>(a, gen_v<T>(ts...));
}
template <typename T, typename V>
typename enable_if<is_class<T>::value == 0>::type fill_v(T& t, const V& v) {
    t = v;
}
template <typename T, typename V>
typename enable_if<is_class<T>::value != 0>::type fill_v(T& t, const V& v) {
    for (auto& e : t) fill_v(e, v);
}

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int M, D;
    cin >> M >> D;
    int cnt = 0;
    rep(m, 1, M + 1) {
        rep(d, 1, D + 1) {
            if (d >= 20 && (d % 10) >= 2 && (d / 10) * (d % 10) == m) { cnt++; }
        }
    }
    cout << cnt << endl;
    return 0;
}
