#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
inline LL read() {
    LL x = 0, fh = 1;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-')
            fh = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = (x << 1) + (x << 3) + c - '0';
        c = getchar();
    }
    return x * fh;
}
const LL MOD = 1e9 + 7;
LL n, a1, a2, a3;
int main() {
	n = read();
	a1 = 1, a2 = 1, a3 = 1;
	while (n--) {
		a1 = a1 * 10 % MOD;
		a2 = a2 * 9 % MOD;
		a3 = a3 * 8 % MOD;
	}
	cout << (((a1 + a3) % MOD + MOD - a2) % MOD + MOD - a2) % MOD << '\n';
	return 0;
}