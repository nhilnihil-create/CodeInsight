#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    ll N; cin >> N;
    set<pair<ll,ll>> S;
    rep(i,N) {
        ll x, l; cin >> x >> l;
        S.insert(make_pair(x + l, x - l));
    }

    auto x = S.begin();
    while (1) {
        auto y = next(x);
        if (y == S.end()) break;
        if (x->first <= y->second) {
            x = y;
            continue;
        } else {
            S.erase(y);
        }
    }
    cout << S.size() << endl;
}
