#include <bits/stdc++.h>

using namespace std;

long long lcm(long long a, long long b) {
	return a / __gcd(a, b) * b;
}

int main() {

	int n, m;
	scanf("%d %d", &n, &m);

	vector<int> a(n);
	for(int &x : a) scanf("%d", &x), x /= 2;

	long long l = 1;

	for(int x : a) {
		l = lcm(l, 1LL * x);
		if(l > m) return printf("0\n"), 0;
	}
	int cnt[2] = {0, 0};
	for(int x : a) {
		cnt[l / x % 2]++;
	}
	if(cnt[0]) return printf("0\n"), 0;

	m /= l;

	printf("%d\n", (m + 1) / 2);
}
