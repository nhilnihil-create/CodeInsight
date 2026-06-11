#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long



#if 0
const int MOD = ;

inline int lgput(int a, int b) {
    int ans = 1;
    while(b > 0) {
        if(b & 1) ans = (1LL * ans * a) % MOD;
        b >>= 1;
        a = (1LL * a * a) % MOD;
    }
    return ans;
}

inline void mod(int &x) {
    if(x >= MOD)
        x -= MOD;
}

inline void add(int &x, int y) {
    x += y;
    mod(x);
}

inline void sub(int &x, int y) {
    x += MOD - y;
    mod(x);
}

inline void mul(int &x, int y) {
    x = (1LL * x * y) % MOD;
}

inline int inv(int x) {
    return lgput(x, MOD - 2);
}
#endif

#if 0
int fact[], invfact[];

inline void prec(int n) {
    fact[0] = 1;
    for(int i = 1; i <= n; i++) {
        fact[i] = (1LL * fact[i - 1] * i) % MOD;
    }
    invfact[n] = lgput(fact[n], MOD - 2);
    for(int i = n - 1; i >= 0; i--) {
        invfact[i] = (1LL * invfact[i + 1] * (i + 1)) % MOD;
    }
}

inline int comb(int n, int k) {
    if(n < k) return 0;
    return (1LL * fact[n] * (1LL * invfact[k] * invfact[n - k] % MOD)) % MOD;
}
#endif

using namespace std;

const int MAXN = (int) 1e5;

int main() {
#if 0
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int i, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;

    vector <ll> a(n);
    for(i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector < bitset <MAXN + 1> > eqs(60);

    vector <int> where(n, -1), sol(n, -1);
    ll ans = 0;

    for(int bit = 59; bit >= 0; bit--) {
        int cnt = 0;
        for(i = 0; i < n; i++) {
            if(a[i] & (1LL << bit)) {
                eqs[bit][i] = 1;
                cnt++;
            }
            else {
                eqs[bit][i] = 0;
            }
        }
        eqs[bit][n] = 1;

        if(cnt & 1) {
            ans += (1LL << bit);
            continue;
        }

        for(i = 0; i < n; i++) {
            if(eqs[bit][i] && where[i] != -1) {
                eqs[bit] ^= eqs[where[i]];
            }
        }

        int pos = -1;
        for(i = 0; i < n; i++) {
            if(eqs[bit][i]) {
                pos = i;
                break;
            }
        }
        if(pos == -1 && eqs[bit][n]) {
            continue;
        }
        ans += (2LL << bit);
        if(pos != -1) {
            where[pos] = bit;
            sol[pos] = eqs[bit][n];
            for(i = n - 1; i > pos; i--) {
                if(eqs[bit][i] && where[i] != -1) {
                    sol[pos] ^= sol[where[i]];
                }
            }
        }
    }

    cout << ans;

    return 0;
}

