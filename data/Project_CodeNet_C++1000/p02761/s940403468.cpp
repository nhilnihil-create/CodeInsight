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
    int N, M;
    cin >> N >> M;
    string ans = string(N, ' ');
    int s;
    char c;
    rep(i, M) {
        cin >> s >> c;
        if(ans.at(s - 1) == ' ' || ans.at(s - 1) == c)
            ans.at(s - 1) = c;
        else {
            ans.assign("-1");
            break;
        }
    }
    if(ans.length() > 1 && ans.at(0) == '0') ans.assign("-1");
    if(ans != "-1")
        rep(i, N) if(ans.at(i) == ' ') ans.at(i) =
            ((i > 0) || (N == 1) ? '0' : '1');
    cout << ans << endl;
}