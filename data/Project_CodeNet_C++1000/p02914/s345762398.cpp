#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int L = 60; 
ll basis[L];

void insert_vec(ll msk) {
    for (int i = L-1; i >= 0; i--) {
        if (!(msk&(1ll<<i))) continue;
        if (!basis[i]) {
            basis[i] = msk; return;
        }
        msk ^= basis[i];
    }
}

void solve() {
    int n; cin >> n;
    vector<long long> a(n);
    ll sum = 0;
    for (auto& x: a) {
        cin >> x;
        sum ^= x;
    }
    for (int i = L-1; i >= 0; i--) {
        if (sum & (1ll<<i)) {
            for (auto& x: a) {
                if (x & (1ll<<i)) x ^= 1ll<<i;
            }
        }
    }
    for (auto& x: a) {
        insert_vec(x);
    }
    ll y = 0;
    for (int i = L-1; i >= 0; i--) {
        if (!basis[i]) continue;
        if (y & (1ll<<i)) continue;
        y ^= basis[i];
    }
    ll res = (y<<1) + sum;
    cout << res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    cout << endl;
}
