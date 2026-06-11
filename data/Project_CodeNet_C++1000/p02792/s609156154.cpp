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

template <typename T> bool chmin(T &a, const T &b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

int main() {
    int N;
    cin >> N;
    vector<vector<int>> table(11, vector<int>(11, 0));
    string NUM;
    rep(i, 1, N + 1) {
        NUM = to_string(i);
        table.at(NUM[0] - '0').at(NUM.back() - '0')++;
    }

    int total = 0;
    rep(i, 10) rep(j, 10) total += table[i][j] * table[j][i];
    cout << total << endl;
}
