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
    deque<char> S;
    string tmp;
    cin >> tmp;
    int a = tmp.size();
    S.resize(a);
    rep(i, a) S[i] = tmp[i];

    int Q, q, f;
    char c;

    cin >> Q;
    bool rev = 0;
    rep(i, Q) {
        cin >> a;
        if(a == 1)
            rev = !rev;
        else {
            cin >> f >> c;
            if(f - int(rev) == 1) {
                S.push_front(c);
            } else {
                S.push_back(c);
            }
        }
    }
    if(rev) reverse(S.begin(), S.end());
    for(auto a : S) {
        cout << a;
    }
}