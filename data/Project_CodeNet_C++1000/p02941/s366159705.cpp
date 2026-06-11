#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 2e5 + 5;

int n;
int A[N];
int B[N];
boolean inq[N];

boolean check(int p) {
	return B[p] >= B[(p + n - 1) % n] + B[(p + 1) % n];
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", A + i);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", B + i);
	}
	queue<int> Q;
	for (int i = 0; i < n; i++) {
		if (check(i)) {
			inq[i] = true;
			Q.push(i);
		}
	}
	long long ans = 0;
	while (!Q.empty()) {
		int p = Q.front();
		Q.pop();
		inq[p] = false;
		int pre = (p + n - 1) % n, suf = (p + 1) % n;
		int sum = B[pre] + B[suf];
		int t = max(0, (B[p] - A[p]) / sum);
		if (!t && B[p] != A[p]) {
			puts("-1");
			return 0;
		}
		ans += t;
		B[p] -= sum * t;
		if (!inq[pre] && check(pre)) {
			inq[pre] = true;
			Q.push(pre);
		}
		if (!inq[suf] && check(suf)) {
			inq[suf] = true;
			Q.push(suf);
		}
	}
	for (int i = 0; i < n; i++) {
		if (A[i] ^ B[i]) {
			puts("-1");
			return 0;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
