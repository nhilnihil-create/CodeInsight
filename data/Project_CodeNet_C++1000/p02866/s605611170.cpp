#include <bits/stdc++.h>
#define rep(begin, end) for (i=begin;i<end;i++)
#define init(arr, end, val) for (i=0;i<end;i++) arr[i] = val;
#define printint(i0, i1) printf("%d %d\n", i0, i1)

using namespace std;
const int inf = pow(10,9);
const int nil = -1;
const long long MOD = 998244353;
long long i, n, m, k, ans;
long long d[100001];
typedef long long ll;

ll modpow(ll a, ll n, ll mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}



int main() {
    scanf(" %lld", &n);
    init(d, n+1, 0);
    scanf(" %lld", &k);
    if (k != 0) {
        printf("0\n"); exit(0);
    }
    d[0]++;
    rep(1,n) {
        scanf(" %lld", &k);
        if (k == 0) {
            printf("0\n"); exit(0);
        } else {
            d[k]++;
        }
    }
    ans = 1;
    rep(1, n) {
        ans = ans * modpow(d[i-1], d[i], MOD) % MOD;
    }

    printf("%lld\n", ans);
}