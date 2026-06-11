#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for(int i = int(a); i < int(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define all(x) (x).begin(), (x).end()
const long long INFLL = 1LL << 60;
const int INFINT = 1 << 30;
const long long MOD = 1e9 + 7;

template <typename T> bool chmax(T &a, const T &b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

int main() {
    int N, K;
    ll max = -1;
    cin >> N >> K;
    vector<ll> P(N), Q(N + 1, 0);
    rep(i, N) { cin >> P.at(i); }
    rep(i, N) { Q.at(i + 1) = 1 + Q.at(i) + P.at(i); }

    rep(i, N + 1 - K) { chmax(max, Q.at(i + K) - Q.at(i)); }
    cout << fixed << max / 2.0 << endl;
}
