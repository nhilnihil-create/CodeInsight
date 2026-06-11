#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 200'010, P = 10'010;
char s[N];
int r[N], cnt[P];

int main() {
    int n, p;
    scanf("%d%d", &n, &p);
    scanf("%s", s + 1);
    ll ans = 0;
    if (p == 2 || p == 5) {
        for (int i = 1; i <= n; i++) {
            if ((s[i] - '0') % p == 0) ans += i;
        }
        printf("%lld\n", ans);
        return 0;
    }
    int pw = 1;
    cnt[0] = 1;
    for (int i = n; i >= 1; i--) {
        r[i] = (pw * (s[i] - '0') + r[i + 1]) % p;
        cnt[r[i]]++;
        pw = 10 * pw % p;
    }
    for (int i = 0; i < p; i++) ans += 1ll * cnt[i] * (cnt[i] - 1) / 2;
    printf("%lld\n", ans);
}
