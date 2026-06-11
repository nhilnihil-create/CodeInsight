#include <bits/stdc++.h>

using namespace std;

using ll = long long;

constexpr int LOG_MAXV = 60;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<ll> v(n);
    ll all_xor = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        all_xor ^= v[i];
    }
    for (int i = 0; i < n; i++) {
        v[i] &= (all_xor ^ ((1LL << LOG_MAXV) - 1));
    }

    int rank = 0;
    for (int col = LOG_MAXV - 1; col >= 0; --col) {
        int pivot = -1;
        for (int row = rank; row < n; ++row) {
            if (v[row] & (1LL << col)) {
                pivot = row;
                break;
            }
        }
        if (pivot == -1) continue;
        swap(v[pivot], v[rank]);
        for (int row = 0; row < n; ++row) {
            if (row != rank && (v[row] & (1LL << col))) {
                v[row] ^= v[rank];
            }
        }
        ++rank;
    }
 
    ll red = 0;
    ll ans = all_xor;
    for (int i = 0; i < n; i++) {
        if (red < (red ^ v[i])) red ^= v[i];
        ans = max(ans, red * 2 + all_xor);
    }
    cout << ans << "\n";
    return 0;
}
