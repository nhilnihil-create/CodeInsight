#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	int N, a, b, c;
	cin >> N;
	vector<ll> A(N), B = A;
	for (int i = 0;i < N;i++) {
		cin >> A[i];
	}
	for (int i = 0;i < N;i++) {
		cin >> B[i];
	}

	queue<int> Q;
	for (int i = 0;i < N;i++) {
		a = i - 1; if (a == -1)a = N - 1;
		b = i;
		c = i + 1; if (c == N)c = 0;

		if (B[b] - A[b] >= B[a] + B[c])Q.push(b);
	}

	ll ans = 0;

	while (!Q.empty()) {
		b = Q.front();
		a = b - 1; if (a == -1)a = N - 1;
		c = b + 1; if (c == N)c = 0;
		Q.pop();

		if (B[b] - A[b] >= B[a] + B[c]) {
			ans += (B[b] - A[b]) / (B[a] + B[c]);
			B[b] = (B[b] - A[b]) % (B[a] + B[c]) + A[b];
			Q.push(a);
			Q.push(c);
		}
	}
	for (int i = 0;i < N;i++) {
		if (A[i] != B[i])ans = -1;
	}
	cout << ans << endl;
}
