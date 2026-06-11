#include <bits/stdc++.h>
#define lowbit(i) ((i)&(-i))
#define ls (p << 1)
#define rs (p << 1 | 1)
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const double pi = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int MAXN =  + 15;

int main() {
#ifdef CitricAcid
    freopen ("input.txt", "rt", stdin);
#endif

    ll n;
    scanf("%lld", &n);
    ll res = 0;
    for(int i = 1; i <= n; i++) {
        res += (n + 1 - i) * i;
    }
    for(int i = 1; i < n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        if(u > v) swap(u, v);
        res -= 1ll * u * (n - v + 1);
    }
    printf("%lld\n", res);

#ifdef CitricAcid
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}
/*
# author : CitricAcid
# date : 2020/07/26
*/