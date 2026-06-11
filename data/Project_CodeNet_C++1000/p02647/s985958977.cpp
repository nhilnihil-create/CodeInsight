#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
typedef long long ll;
template <typename T> void chkmax(T &x, T y) {x = max(x, y); }
template <typename T> void chkmin(T &x, T y) {x = min(x, y); } 
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
int n, k, a[MAXN];
bool work() {
	static int s[MAXN];
	memset(s, 0, sizeof(s));
	for (int i = 1; i <= n; i++) {
		int l = max(1, i - a[i]), r = min(n, i + a[i]);
		s[l]++, s[r + 1]--;
	}
	bool res = false;
	for (int i = 1; i <= n; i++) {
		s[i] += s[i - 1];
		if (s[i] != a[i]) {
			res = true;
			a[i] = s[i];
		}
	}
	return res;
}
int main() {
	read(n), read(k);
	for (int i = 1; i <= n; i++)
		read(a[i]);
	for (int i = 1; i <= k; i++)
		if (!work()) break;
	for (int i = 1; i <= n; i++)
		printf("%d ", a[i]);
	printf("\n");
	return 0;
}
