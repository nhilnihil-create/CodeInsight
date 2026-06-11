#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
inline int read() {
    int x = 0, fh = 1;
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
const int N = 2010, MOD = 1e9 + 7;
int n, i;
LL f[N];
int main() {
	n = read();
	f[3] = f[4] = 1;
	for (i = 5; i <= n; i++) f[i] = ((f[i - 2] + f[i - 3]) % MOD + f[i - 4]) % MOD;
	cout << f[n] << '\n';
	return 0;
}