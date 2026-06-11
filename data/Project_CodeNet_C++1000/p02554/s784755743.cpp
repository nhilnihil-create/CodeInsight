#include <bits/stdc++.h>
// #include <atcoder/all> // NOTE: AtCoderライブラリ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
// using namespace atcoder; // NOTE: AtCoderライブラリ
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef pair<int, int> pii;
// #define INF __INT32_MAX__
#define INF 1e9
#define LINF __LONG_LONG_MAX__

const ll MOD = 1e9 + 7;
long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;

        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

ll N; 

ll dfs(string s, int n) {
    if (n == N) {
        bool ok0 = false, ok9 = false;
        for (int i = 0; i < N; i++) {
            if (s.at(i) == '0') ok0 = true;
            if (s.at(i) == '9') ok9 = true;
        }
        if (ok0 && ok9) {
            return 1;
        } else {
            return 0;
        }
    }

    ll cnt = 0;
    for (int i = 0; i < 10; i++) {
        string tmp = s;
        tmp += (i + '0');
        cnt += dfs(tmp, n + 1);
    }

    return cnt;
}

int main() {
    cin >> N;

    if (N == 1) {
        cout << 0 << endl;
        return 0;
    }

    ll ans = (modpow(10, N, MOD) - (modpow(9, N, MOD) * 2) % MOD + modpow(8, N, MOD)) % MOD;
    if (ans < 0) ans += MOD;
    cout << ans << endl;
}
