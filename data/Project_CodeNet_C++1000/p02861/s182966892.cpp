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
    map<int, int> c;
    vector<int> x(N), y(N);
    rep(i, N) { cin >> x[i] >> y[i]; }
    double dist = 0;
    rep(i, N) {
        rep(j, i + 1, N) {
            dist +=
                sqrt(pow(1. * (x[i] - x[j]), 2) + pow(1. * (y[i] - y[j]), 2));
        }
    }
    dist *= 2;
    dist /= N;
    cout << fixed << setprecision(12) << dist << endl;
}
