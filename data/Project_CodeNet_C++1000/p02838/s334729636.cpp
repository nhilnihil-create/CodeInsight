#include <bits/stdc++.h>
#define DAU  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define PLEC exit(0);
using namespace std;
const int MOD(1e9 + 7);
int freq[62][2], n, curr, res;
long long x, p2[62];
int main() {
    DAU
    p2[0] = 1;
    for (int i = 1; i < 62; ++i)
        p2[i] = p2[i - 1] << 1;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        for (int bit = 0; bit < 62; ++bit)
            ++freq[bit][!!(x & p2[bit])];
    }
    for (int bit = 0; bit < 62; ++bit)
        res = (res + (1LL * ((1LL * freq[bit][0] * freq[bit][1]) % MOD) * (p2[bit] % MOD)) % MOD) % MOD;
    cout << res;
    PLEC
}
