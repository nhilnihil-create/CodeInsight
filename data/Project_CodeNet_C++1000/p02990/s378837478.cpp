#include <bits/stdc++.h>

using namespace std;
using llong = long long int;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define stl_rep(itr, x) for (auto itr = x.begin(); itr != x.end(); ++itr)
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()

const int MOD = 1000000007;
const int INF = 1000000000;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

const int MAX = 200101;
long long fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}


int main (int argc, char *argv[]) {
    cin.tie(0); 
    ios::sync_with_stdio(false);
    // for file input
    /* ifstream in("input.txt");
    ifstream in("input.txt"); */

    COMinit();

    int n, k;
    cin >> n >> k;

    int red = n - k, blue = k;
    for (int i = 1; i <= k; ++i) {
        llong res = COM(red + 1, i) * COM(blue - 1, i - 1);
        res %= MOD;
        cout << res << endl;
    }

    return 0;
}