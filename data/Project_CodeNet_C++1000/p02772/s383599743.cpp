#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
inline LL read() {
	LL x = 0, fh = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') fh = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = (x << 1) + (x << 3) + c - '0';
		c = getchar();
	}
	return x * fh;
}
int n, x, flag, i;
int main() {
	n = read();
	for (i = 1; i <= n; i++) {
		x = read();
		if (x % 2 == 0) if (x % 3 != 0 && x % 5 != 0) flag = 1;
	}
	cout << (!flag ? "APPROVED\n" : "DENIED\n");
	return 0;
}