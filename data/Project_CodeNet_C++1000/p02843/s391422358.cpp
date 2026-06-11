#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for(int i = int(a); i < int(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define all(x) (x).begin(), (x).end()
const long long MOD = 1e9 + 7;

template <typename T> bool chmax(T &a, const T &b) {
    if(a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <typename T> bool chmin(T &a, const T &b) {
    if(a > b) {
        a = b;
        return 1;
    }
    return 0;
}

int main() {
    int N;
    cin >> N;
    if(N < 100)
        cout << 0 << endl;
    else if(N < 106)
        cout << 1 << endl;
    else {
        vector<bool> c(N + 1, 0);
        rep(i, 100, 106) c[i] = 1;
        rep(i, 107, N + 1) {
            c[i] = c[i - 100] || c[i - 101] || c[i - 102] || c[i - 103] ||
                   c[i - 104] || c[i - 105];
        }
        cout << c[N] << endl;
    }
}
