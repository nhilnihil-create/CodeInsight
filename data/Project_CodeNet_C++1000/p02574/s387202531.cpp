#include <cstdio>
 
const int N = 1e6 + 5;
const int SQRT_NUM = 1000 + 5; // sqrt{max a_i}

int n;

int cnt[N];
 
int gcd(int x, int y) { return x % y == 0 ? y : gcd(y, x % y); }
 
int main() {
	std::scanf("%d", &n);
	int gcd_all = 0;
	for(int i = 1; i <= n; i++) {
		int x;
		std::scanf("%d", &x);
		cnt[x]++;
		gcd_all = gcd(gcd_all, x);
	}
	if(gcd_all != 1) { std::puts("not coprime"); return 0; }
	for(int i = 2; i < N; i++) {
		int tot = 0;
		for(int j = i; j < N; j += i) tot += cnt[j];
		if(tot > 1) { std::printf("setwise coprime"); return 0; }
	}
	std::puts("pairwise coprime");
	return 0;
}