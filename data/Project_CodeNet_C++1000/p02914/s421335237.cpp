#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<ll> a(n);
    vector<int> bit(60);
    rep(i, 0, n) {
        cin >> a[i];
        rep(j, 0, 60) if (a[i] & (1LL << j)) bit[j]++;
    }

    ll odd = 0;
    rep(i, 0, 60) if (bit[i] % 2) odd += 1LL << i;

    rep(i, 0, n) a[i] &= ~odd;

    int j = 0, rank = 0;
    for (int i = 59; i >= 0; i--) {
        for (j = rank; j < n; j++)
            if (a[j] & (1LL << i))
                break;
        if (j == n)
            continue;
        if (j > rank)
            a[rank] ^= a[j];
        for (j = rank + 1; j < n; j++) {
            a[j] = min(a[j], a[j] ^ a[rank]);
        }
        rank++;
    }
    ll even = 0;
    rep(i, 0, n) even = max(even, even ^ a[i]);
    cout << even * 2 + odd << endl;

    return 0;
}