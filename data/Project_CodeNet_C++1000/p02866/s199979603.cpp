#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

constexpr long long mod = 998244353;
long long int mod_pow(long long int x, long long int n, long long int p) {
    long long int res = 1;
    while (n > 0) {
        if (n & 1)
            res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}
#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vi d(n);
    rep(i, n) cin >> d[i];

    if (d[0] != 0) {
        cout << 0 << endl;
    } else {
        bool b = true;

        ll sum = 1;
        vll cnt(n, 0);
        int idx = 0;
        for (int i = 1; i < n; i++) {
            if (d[i] == 0) {
                b = false;
                break;
            }

            cnt[d[i]]++;

            idx = max(idx, d[i]);
        }
        cnt[0] = 1;

        for (int i = 1; i <= idx; i++) {
            sum *= mod_pow(cnt[i - 1], cnt[i], mod);
            sum %= mod;
        }

        if (b) {
            cout << sum << endl;
        } else {
            cout << 0 << endl;
        }
    }
}