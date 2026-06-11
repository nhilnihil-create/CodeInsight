#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, pos[60];
ll p[60];
ll a[100005], b[100005];
ll sum = 0, occ = 0, ans = 0;
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%lld", a + i), sum ^= a[i], occ |= a[i];

    int m = 0;
    for (int i = 59; i >= 0; --i) {
        if ((~occ >> i) & 1)
            continue;
        else if ((sum >> i) & 1) {
            ans |= 1LL << i;
            continue;
        }

        pos[m] = i;
        for (int j = 0; j < n; ++j)
            if ((a[j] >> i) & 1) b[j] |= 1LL << m;
        ++m;
    }
    memset(p, -1, sizeof p);
    for (int i = 0; i < n; ++i) {
        for (int k = 0; k < m; ++k) {
            if ((~b[i] >> k) & 1) continue;
            if (p[k] == -1) {
                p[k] = b[i];
                break;
            }
            b[i] ^= p[k];
        }
    }
    ll cur = 0;
    for (int i = 0; i < m; ++i) {
        if (((~cur >> i) & 1) && p[i] != -1) cur ^= p[i];
        if ((cur >> i) & 1) ans += 1LL << (pos[i] + 1);
    }
    printf("%lld\n", ans);
}