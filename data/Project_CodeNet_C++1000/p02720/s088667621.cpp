#include "bits/stdc++.h"
using namespace std;
int main() {
	long long K; cin >> K;
	queue<long long>Q;
	Q.push(1); Q.push(2); Q.push(3); Q.push(4); Q.push(5); Q.push(6); Q.push(7); Q.push(8); Q.push(9);
	long long ans = 0;
	for (long long i = 0; i < K; i++) {
		long long x = Q.front();
		Q.pop();
		ans = x;
		if (x % 10 != 0) Q.push(10 * x + (x % 10) - 1);
		Q.push(10 * x + (x % 10));
		if (x % 10 != 9) Q.push(10 * x + (x % 10) + 1);
	}
	cout << ans << endl;
}