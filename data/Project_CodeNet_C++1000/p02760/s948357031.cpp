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
    int list[3][3];
    rep(i, 3) rep(j, 3) cin >> list[i][j];
    bool check[3][3] = {};
    int N;
    cin >> N;
    int b;
    rep(n, N) {
        cin >> b;
        rep(i, 3) rep(j, 3) if(b == list[i][j]) check[i][j] = 1;
    }
    int bingo = 0;
    rep(i, 3) {
        if(check[i][0] && check[i][1] && check[i][2]) bingo++;
        if(check[0][i] && check[1][i] && check[2][i]) bingo++;
    }
    if(check[0][0] && check[1][1] && check[2][2]) bingo++;
    if(check[2][0] && check[1][1] && check[0][2]) bingo++;
    cout << (bingo > 0 ? "Yes" : "No") << endl;
}