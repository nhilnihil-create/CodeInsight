#pragma GCC optimize ("O3")
#pragma GCC target ("tune=native")
#pragma GCC target ("avx")

#include <cstdio>
using ll = long long;

// 処理内容
int main() {

    ll n; scanf("%lld", &n);

    ll ans[1024];
    for (ll j = 1, j_end = n-1; j <= j_end; j++) {
        ans[j-1] = 0;
        for (ll l = j & -j; l; ans[j-1]++) l >>= 1;
    }
    for (ll i = 0, i_end = n-2; i <= i_end; i++) {
        for (ll j = 0, j_end = n-2-i; j <= j_end; j++) {
            printf("%lld%c", ans[j], j == j_end ? '\n' : ' ');
        }
    }
    
}