#include <bits/stdc++.h>
using namespace std;
//#include <atcoder/dsu>
//using namespace atcoder;

typedef long long int ll;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define all(v) (v).begin(), (v).end()
#define sz(x) int(x.size())
const ll mod = 1000000007;
const ll INF = 1001001001001001000;

ll modpow(ll A, ll N) {
    ll RET = 1;
    // 例えば3=101(2)なので、下位bitから順に1ならa倍する
    while (N) {
        if (N & 1) RET = RET * A % mod;
        A = A * A % mod;
        N >>= 1;
    }
    return RET;
}

ll comb(ll N, ll R) {
    if (N < 0 || R < 0 || N < R) return 0;
    // numerator/denominator
    ll NUME = 1, DENO = 1;
    R = min(R, N-R);
    for (int i = 1; i <= R; i++) {
        NUME = NUME * N % mod;
        DENO = DENO * i % mod;
        N--;
    }
    return NUME * modpow(DENO, mod-2) % mod;
}

int main() {
    int x,y; cin >> x >> y;
    bool ans = 1;
    if ((x+y)%3 != 0) ans = 0;
    if (2*x-y<0 || 2*y-x<0) ans = 0;
    if (!ans) {
        printf("0\n");
        return 0;
    }
    ll a = (2*x-y)/3, b = (2*y-x)/3;
    ll anss = comb(a+b,a);
    cout << anss << endl;
    return 0;
}
