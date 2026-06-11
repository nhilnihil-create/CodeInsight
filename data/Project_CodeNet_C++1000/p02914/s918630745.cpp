#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    // 吐き出し法(row reduction)、xorのtotalのbitが1の部分はそのまま
    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    ll xtotal = 0;
    rep(i, N) xtotal ^= A[i];
    rep(i, N) A[i] &= ~xtotal;
    ll ans = 0;
    // 吐き出し法
    int r = 0;
    for (int i = 60; i >= 0; i--) {
        int j = r;
        for (; j < N; j++) {
            if ((A[j]>>i)&1) {
                swap(A[j], A[r]);
                break;
            }
        }
        if (j == N) continue;
        for (int k = 0; k < N; k++) {
            if (k == r) continue;
            if ((A[k]>>i)&1) A[k] ^= A[r];
        }
        r++;
    }
    rep(i, N) ans ^= A[i];
    ans *= 2;
    ans += xtotal;
    cout << ans << '\n';
    return 0;
}