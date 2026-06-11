#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
template <typename T> void chkmax(T &x, T y) {x = max(x, y); }
template <typename T> void chkmin(T &x, T y) {x = min(x, y); } 
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
template <typename T> void write(T x) {
	if (x < 0) x = -x, putchar('-');
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
template <typename T> void writeln(T x) {
	write(x);
	puts("");
}
int a[MAXN];
int main() {
	int n, power = 1; read(n);
	while (power < n) power <<= 1;
	if (n == power) {
		puts("No");
		return 0;
	}
	puts("Yes");
	power >>= 1;
	if (n % 4 == 0) {
		for (int i = 1; i <= n - 1; i++)
			a[i] = i;
		swap(a[power - 1], a[n ^ power]);
		for (int i = 1; i <= n - 2; i++)
			printf("%d %d\n", a[i], a[i + 1]);
		printf("%d %d\n", a[n - 1], n + a[1]);
		for (int i = 1; i <= n - 2; i++)
			printf("%d %d\n", n + a[i], n + a[i + 1]);
		printf("%d %d\n", n, power);
		printf("%d %d\n", 2 * n, n ^ power);
	}
	if (n % 4 == 1) {
		for (int i = 2; i <= n - 1; i++)
			printf("%d %d\n", i, i + 1);
		printf("%d %d\n", n, n + 2);
		for (int i = 2; i <= n - 1; i++)
			printf("%d %d\n", n + i, n + i + 1);
		printf("%d %d\n", 1, 2);
		printf("%d %d\n", n + 1, 3);
	}
	if (n % 4 == 2) {
		for (int i = 2; i <= n - 1; i++)
			a[i] = i;
		swap(a[power - 1], a[n ^ power]);
		if ((n ^ power) == 2 && n != 6) swap(a[power - 2], a[3]);
		for (int i = 2; i <= n - 2; i++)
			printf("%d %d\n", a[i], a[i + 1]);
		printf("%d %d\n", a[n - 1], n + a[2]);
		for (int i = 2; i <= n - 2; i++)
			printf("%d %d\n", n + a[i], n + a[i + 1]);
		printf("%d %d\n", n, power);
		printf("%d %d\n", 2 * n, n ^ power);
		printf("%d %d\n", 1, 2);
		printf("%d %d\n", 1 + n, 3);
	}
	if (n % 4 == 3) {
		for (int i = 1; i <= 2 * n - 1; i++)
			printf("%d %d\n", i, i + 1);
	}
	return 0;
}