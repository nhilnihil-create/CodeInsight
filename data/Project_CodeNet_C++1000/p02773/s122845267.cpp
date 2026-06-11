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
const int N = 2e5 + 10;
int n, sum, maxx, i;
string s[N];
int main() {
	n = read();
	for (i = 1; i <= n; i++) cin >> s[i];
	sort(s + 1, s + 1 + n);
	for (i = 1, sum = 1; i <= n; i++)
		if (s[i] != s[i + 1]) {
			maxx = max(maxx, sum);
			sum = 1;
		}
		else sum++;
	for (i = 1, sum = 1; i <= n; i++)
		if (s[i] != s[i + 1]) {
			if (sum == maxx) cout << s[i] << '\n';
			sum = 1;
		}
		else sum++;
	return 0;
}