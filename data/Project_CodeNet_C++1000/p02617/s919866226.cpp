#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    ll N; cin >> N;
    ll res = 0;
    for (int i = 1; i <=N; i++) res += (ll)(i * (i + 1LL)) / 2LL;
    rep(i, N-1) {
        ll u, v; cin >> u >> v;
        if (u > v) swap(u, v);
        res -= u * (N - v + 1);
    }
    cout << res << endl;
}
