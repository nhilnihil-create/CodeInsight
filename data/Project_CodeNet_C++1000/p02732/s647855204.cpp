#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for(int i = int(a); i < int(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define all(x) (x).begin(), (x).end()
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
const long long INFLL = 1LL << 60;
const long long MOD = 1e9 + 7;

int main() {
    int N;
    cin >> N;
    vector<ll> A(N), co(N, 0);
    rep(i, N) {
        cin >> A[i];
        co.at(A[i] - 1)++;
    }
    ll ch = 0;
    rep(i, N) ch += co[i] * (co[i] - 1) / 2;
    rep(i, N) cout << ch - co[A[i] - 1] + 1 << endl;
}