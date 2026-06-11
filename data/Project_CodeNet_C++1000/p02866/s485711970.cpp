#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < n; i++)
#define ALL(a) a.begin(), a.end()
#define MOD 998244353
using namespace std;
typedef long long ll;

ll power(ll n, ll p, ll mod) {
    ll ans = 1;
    while (p > 0) {
        if (p & 1) ans = ans * n % mod;
        n = n * n % mod;
        p >>= 1;
    }
    return ans;
}

int main() {
    int N; cin >> N;
    vector<int> D(N);
    REP(i, 0, N) cin >> D[i];

    int count[N] = {};
    REP(i, 0, N) count[D[i]]++;

    if (D[0] != 0 || count[0] != 1) {
        cout << 0 << endl;
        return 0;
    }
    
    ll ans = 1; int M = 1;
    REP(i, 1, N) {
        if (count[i] == 0) break;
        ans = (ans * power(count[i - 1], count[i], MOD)) % MOD;
        M += count[i];
    }

    if (N == M) cout << ans % MOD << endl;
    else cout << 0 << endl;

    return 0;
}