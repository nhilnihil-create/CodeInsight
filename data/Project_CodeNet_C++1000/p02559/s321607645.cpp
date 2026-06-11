#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;

#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, m, n) for (int i = (m); i < (int)(n); i++)

template <typename T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template <typename T>
bool chmin(T &a, const T &b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

int main() {
    ll N, Q, a, t, p, x, l, r;
    cin >> N >> Q;
    fenwick_tree<ll> fw(N);
    REP(i, N) {
        cin >> a;
        fw.add(i, a);
    }
    REP(i, Q) {
        cin >> t;
        if (t == 0) {
            cin >> p >> x;
            fw.add(p, x);
        } else {
            cin >> l >> r;
            cout << fw.sum(l, r) << endl;
        }
    }
}