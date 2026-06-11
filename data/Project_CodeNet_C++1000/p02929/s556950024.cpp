#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define sz(x) ((int)x.size())
#define all(x) x.begin(), x.end()
using pii=pair<int, int>;
using ll=long long;

const int mn = 2e5 + 5;
const int mod = 1e9 + 7;
int n;
char s[mn];

void bye() {
    puts("0");
    exit(0);
}

int main() {
    //cin.sync_with_stdio(0);
#ifdef trote
    freopen("../1.txt", "r", stdin);
#endif
    scanf("%d%s", &n, s + 1);
    n *= 2;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'W') s[i] = 0;
        else s[i] = 1, cnt++;
    }
    if (cnt % 2) bye();
    bool p = 0;
    cnt = 0;
    ll ans = 1;
    for (int i = 1; i <= n; i++) {
        if (s[i] ^ p) {
            cnt++;
        } else {
            ans *= cnt;
            ans %= mod;
            cnt--;
            if (cnt < 0) bye();
        }
        p ^= 1;
        //printf("%d %d %lld\n", i, cnt, ans);
    }
    if (cnt) bye();
    for (int i = 1; i <= n / 2; i++) ans = ans * i % mod;
    printf("%lld\n", ans);

}