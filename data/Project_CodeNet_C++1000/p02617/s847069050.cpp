#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int ans;
signed main () {
    scanf ("%lld", &n);
    for (int i = 1; i <= n; i++) {
        ans += i * (n - i + 1);
    }
    for (int i = 1; i < n; i++) {
        int x, y;
        scanf ("%lld%lld", &x, &y); if (x > y) swap (x, y);
        ans -= x * (n - y + 1);
    }
    printf ("%lld\n", ans);
    return 0;
}
