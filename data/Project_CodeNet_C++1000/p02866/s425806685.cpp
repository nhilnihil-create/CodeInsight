#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 998244353;

long long modpow(long long a, long long n) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % MOD;
        a = a * a % MOD;
        n >>= 1;
    }
    return res;
}

int main() {
    int N; cin >> N;
    int m = 0;
    vector<int> dis(N, 0);
    int t; cin >> t; dis[t]++;
    for (int i = 0; i < N-1; i++) {
        int d; cin >> d;
        dis[d]++;
        m = max(m, d);
    }
    if (dis[0] != 1 || t != 0) {
        cout << 0 << endl;
    } else {
        ll ans = 1;
        for (int i = 1; i <= m; i++) {
            ans = (ans * modpow(dis[i-1], dis[i])) % MOD;
        }
        cout << ans << endl;
    }
}
