#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
const int mod = 1e9 + 7;
int n, m;
int a[maxn], b[maxn], num[maxn];
int read() {
	int x; scanf("%d", &x); return x;
}
int main() {
	#ifdef LOCAL
		freopen("1.in", "r", stdin);
	#endif
	n = read();
	for (int i = 1; i <= n; ++i) a[i] = read();
	int cur = 0;
	for (int i = 1; i <= n; ++i) cur = cur ^ (a[i] ^ a[1]);
	for (int i = 1; i <= n; ++i) cout << (a[i] ^ cur) << ' ';
	cout << endl; 
}	