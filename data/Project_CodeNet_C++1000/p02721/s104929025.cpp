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
    int N, K, C;
    string S;
    cin >> N >> K >> C >> S;
    vector<int> f(K, 0), b(K, 0);
    int d = 0;
    for(int i = 0; i < K; i++) {
        while(S.at(d) == 'x')
            d++;
        f[i] = d + 1;
        d += C + 1;
    }
    d = N - 1;
    for(int i = K - 1; i >= 0; i--) {
        while(S.at(d) == 'x')
            d--;
        b[i] = d + 1;
        d -= C + 1;
    }
    rep(i, K) if(f[i] == b[i]) cout << f[i] << endl;
}