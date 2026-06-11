#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define int long long

// using P = pair<int, int>;

#define REP(i,n) for (int i = 0; i < (n); ++i)
#define FORE(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << '\n'

const int MOD = (int)1e9 + 7;


int mypow(int n, int p) {
    // cout << "p=" << p << endl;
    if (p == 0) {
        return 1;
    }

    if (p == 1) {
        return n;
    }

    if (p % 2 == 0) {
        int a = mypow(n, p /2);
        return (a * a) % MOD;
    } else {
        return (n * mypow(n, p - 1)) % MOD;
    }
}


int combination(int n, int r) {
    int i;
    int ans;
    int nume = 1;
    FORE (i,n-r+1,n) {
        nume = (nume * i) % MOD;
    }

    int deno = 1;
    FORE(i,1, r) {
        deno = (deno * i) % MOD;
    }

    ans = (nume * mypow(deno, MOD - 2)) % MOD;

    debug(nume);
    debug(deno);
    debug(ans);

    return ans;
}

signed main() {
    int N, A, B;
    cin >> N >> A >> B;

    int ans = mypow(2, N) - 1;
    debug(ans);
    ans = (ans - combination(N, A) + MOD) % MOD;
    debug(ans);

    ans = (ans - combination(N, B) + MOD) % MOD;
    debug(ans);

    cout << ans << endl;

    return 0;
}
