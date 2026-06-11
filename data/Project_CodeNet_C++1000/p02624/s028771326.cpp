#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
#include <bits/stdc++.h>
#define FOR(i, a, b)    for(int i = a; i <= b; i++)
#define REP(i, a, b)    for(int i = a; i >= b; i--)
#define maxN       200005
#define inf        (int) 1e9
#define mode       (int) 1000000007
#define ll         long long

using namespace std;

int n;
int f[10000005];

void enter() {
    scanf("%d", &n);
    FOR(i, 1, n)
        FOR(j, 1, n / i) {
            int k = i * j;
            f[k]++;
        }
}

void solve() {
    ll ans = 0;
    FOR(i, 1, n)
        ans += 1ll * i * f[i];
    printf("%lld", ans);
}

int main() {
    //freopen("main.inp", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    enter();
    solve();
}
