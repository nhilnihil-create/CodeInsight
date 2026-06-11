#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define MOD 1000000007
#define MOD2 998244353
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P;

int main() {
    int n, k;
    cin >> n >> k;
    Int sm[n+2];
    sm[0] = 0;
    // su[0] = 0, su[1] = 0, su[2] = 1, ...
    rep(i,n+1) {
        sm[i+1] = (sm[i] + i) % MOD;
    }
    Int ans = 0;
    for (int i = k; i <= n+1; i++) {
        Int mn = sm[i];
        Int mx = sm[n+1] - sm[n-i+1];
        ans += mx - mn + 1;
        ans %= MOD;
    }
    if (ans < 0) ans += MOD;
    cout << ans << endl;
}