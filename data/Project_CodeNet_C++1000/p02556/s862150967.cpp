#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    int N; cin >> N;
    ll maz = -1e10, miz = INT64_MAX;
    ll maw = -1e10, miw = INT64_MAX;
    vector<pair<int,int>> P(N);
    rep(i,N) {
        ll x, y; cin >> x >> y;
        ll z = x + y;
        if (maz < z) maz = z;
        if (miz > z) miz = z;
        ll w = x - y;
        if (maw < w) maw = w;
        if (miw > w) miw = w;
    }
    cout << max(maz - miz, maw - miw) << endl;
}
