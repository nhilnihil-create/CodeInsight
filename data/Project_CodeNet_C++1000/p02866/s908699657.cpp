#include <bits/stdc++.h>
using namespace std;

#define N 100005

int d[N], n, cnt[N], mx;

const int mod = 998244353;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) {
      scanf("%d", &d[i]);
      cnt[d[i]] ++;
      mx = max(mx, d[i]);
    }
    if (d[1] != 0) return puts("0"), 0;
    for (int i = mx; i >= 0; i --) if (cnt[i] == 0) return puts("0"), 0;
    if (cnt[0] > 1) return puts("0"), 0;
    int ans = 1;
    for (int i = 1; i <= n; i ++) {
      int k = d[i];
      if (k>0) ans = 1ll * ans * cnt[k-1] % mod;
    }
    cout << ans << endl;
    return 0;
}
