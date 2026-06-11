#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 10;
const int INF = 0x3f3f3f3f;
int n;
int a[N], tw = 1, fac[N], cnt[3];
void init(int n) {
	for (int i = 1; i <= n; i++) {
		int t = i;
		fac[i] = fac[i - 1];
		while (t && (t & 1 ^ 1)) {
			fac[i] ++;
			t >>= 1;
		}
	}
}
int fc(int n, int k) {
	return fac[n] - fac[k] - fac[n - k];
}
int main() {
	scanf("%d", &n);
	init(n);
	for (int i = 1; i <= n; i++) {
		char c;
		scanf(" %c", &c);
		a[i] = c - '1';
		if (a[i] == 1)tw = 0;
		int tmp = fc(n - 1, i - 1);
		if (tmp <= 0)cnt[a[i]] ^= 1;
	}
	if (cnt[1])puts("1");
	else {
		if (!tw)puts("0");
		else {
			if (cnt[2])puts("2");
			else puts("0");
		}
	}
	return 0;
}