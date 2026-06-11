#include <bits/stdc++.h>
using namespace std;
int pri[1000020], cnt;
int mark[1000020];
int a[1000020];
int suck[1000020];

void filter(int n) {
	for (int i = 2; i <= n; ++ i) {
		if (!mark[i]) pri[++cnt] = i;
		for (int j = 1; j <= cnt && i * pri[j] <= n; ++ j) {
			mark[i * pri[j]] = 1;
		}
	}
}

bool isa(int n) {
	for (int i = 1; i <= n; ++ i) {
		int t = a[i];
		for (int j = 1; j <= cnt && t > 1; ++ j) {
			if (t % pri[j] == 0) {
				while (t % pri[j] == 0) t /= pri[j];
				if (suck[pri[j]]) return false;
				suck[pri[j]] ++;
			}
			if (t > 1 && !mark[t]) {
				// printf("suck %d", t);
				if (suck[t]) return false;
				suck[t] ++;
				t = 1;
			}
		}
	}
	return true;
}

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i) {
		scanf("%d", a + i);
	}
	filter(1000000);
	if (isa(n)) return puts("pairwise coprime")&0;
	int g = a[1];
	for (int i = 2; i <= n; ++ i) {
		g = gcd(g, a[i]);
	}
	if (g == 1) return puts("setwise coprime")&0;
	puts("not coprime");
}
