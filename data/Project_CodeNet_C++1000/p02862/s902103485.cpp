#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+5;

const int mod = 1e9 + 7;

int fac[N], rfac[N], inv[N];

int main() {
    fac[0] = rfac[0] = fac[1] = rfac[1] = 1;
    inv[0] = 0, inv[1] = 1;
    for (int i = 2; i < N; i ++) {
        fac[i] = 1ll * fac[i-1] * i % mod;
        inv[i] = 1ll * (mod / i) * (mod - inv[mod%i]) % mod;
        rfac[i] = 1ll * rfac[i-1] * inv[i] % mod;
    }
    int x, y;
    scanf("%d %d", &x, &y);
    if ((x+y) % 3) puts("0");
    else {
        int b = x - (x + y) / 3;
        int a = y - (x + y) / 3;
        if (a < 0 || b < 0) puts("0");
        else {
			cerr << a << " " << b << endl;
            int ans = 1ll * fac[a+b] * rfac[b] % mod * rfac[a] % mod;
            cout << ans << endl;
        }
    }
	return 0;
}
