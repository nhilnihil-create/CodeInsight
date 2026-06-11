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
int a, b, c;
int main() {
	a = read(); b = read(); c = read();
	cout << (((a == b && b != c) + (b == c && a != c) + (a == c && a != b) == 1) ? "Yes\n" : "No\n");
	return 0;
}