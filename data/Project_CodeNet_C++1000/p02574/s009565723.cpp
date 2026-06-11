#include<bits/stdc++.h>
using namespace std;

const int N = 1000009;
int n, a[N], prime[N], cnt[N], Exit;

void solve() {
	for (int i = 1; i <= n; ++ i) {
		if (!prime[a[i]]) {
			 if (a[i] != 1) ++ cnt[a[i]];
			if (cnt[a[i]] > 1) {
				Exit = 1;
				return ;
			}
		}
		else {
			for (int j = 1; j <= sqrt(a[i]); ++ j) {
				if (a[i] % j == 0) {
					if (j != 1) ++ cnt[j];
					if (cnt[j] > 1) {
						Exit = 1;
						return ;
					}
					if (j * j != a[i]) {
						if (a[i] / j != 1) ++ cnt[a[i] / j];
						if (cnt[a[i] / j] > 1) {
							Exit = 1;
							return ;
						}
					}
				}
			}
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i) scanf("%d", &a[i]);
	prime[1] = 1;
	for (int i = 2; i <= 1000000; ++ i) 
		if (!prime[i]) 
			for (int j = i + i; j <= 1000000; j += i) prime[j] = 1;
	solve();
	if (Exit == 0) {
		puts("pairwise coprime");
		return 0;
	}
	int x = __gcd(a[1], a[2]);
	if (x == 1) {
		puts("setwise coprime");
		return 0;
	}
	for (int i = 1; i < n - 1; ++ i) {
		x = __gcd(x, a[i + 2]);
		if (x == 1) {
			puts("setwise coprime");
			return 0;
		}
	}
	puts("not coprime");
	return 0;
}