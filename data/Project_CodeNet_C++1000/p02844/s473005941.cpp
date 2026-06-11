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
    string S;
    cin >> N >> S;
    int ans = 0;

    rep(i, 1000) {
        string l;
        if(i < 10)
            l += "00";
        else if(i < 100)
            l += "0";
        l += to_string(i);
        int f = 0;
        for(auto j : S) {
            if(l[f] == j) f++;
            if(f == 3) {
                ans++;
                break;
            }
        }
    }
    cout << ans << endl;
}
