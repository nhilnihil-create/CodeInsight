#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9+7;
int add(int a, int b) {
	return a + b >= mod ? a + b - mod : a + b;
}
int mul(int a, int b) {
	return int(1LL * a * b % mod);
}
int fexp(int b, int e = mod - 2) {
	int ans = 1;
	while(e) {
		if(e & 1) ans = mul(ans, b);
		b = mul(b, b);
		e /= 2;
	}
	return ans;
}

const int N = 500005;

int n, k;

int cnt[N];
int fat[N], ifat[N];
int C(int i, int j) {
	if(j > i) return 0;
	return mul(mul(fat[i], ifat[j]), ifat[i-j]);
}

int main() {

	fat[0] = 1;
	for(int i = 1; i < N; i++) fat[i] = mul(i, fat[i - 1]);

	ifat[N-1] = fexp(fat[N-1]);

	for(int i = N - 2; i >= 0; i--) {
		ifat[i] = mul(i + 1, ifat[i + 1]);
	}

	scanf("%d %d", &n, &k);

	for(int i = 1; i <= k; i++) {
		for(int j = i; j <= k; j += i) {
			cnt[i]++;
		}
	}

	for(int i = 1; i <= k; i++) {
		cnt[i] = fexp(cnt[i], n);
	}

	for(int i = k; i >= 1; i--) {
		for(int j = i + i; j <= k; j += i) {
			cnt[i] = add(cnt[i], mod - cnt[j]);
		}
	}
	int ans = 0;

	for(int i = 1; i <= k; i++) {
		ans = add(ans, mul(i, cnt[i]));
	}
	printf("%d\n", ans);
}
