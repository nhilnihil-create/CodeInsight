#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;
#pragma warning (disable: 4996)

long long N, K;
long long L[1 << 18];

long long solve(long long r) {
	if (r == 0) return (1LL << 60);

	long long ans = 0;
	for (int i = 1; i <= N; i++) {
		ans += (L[i] - 1LL) / r;
	}
	return ans;
}

int main() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) cin >> L[i];

	int cl = 0, cr = (1 << 30), cm, minx = (1 << 30);
	for (int i = 0; i < 34; i++) {
		cm = (cl + cr) / 2;
		if (solve(cm) <= K) { minx = min(minx, cm); cr = cm; }
		else { cl = cm; }
	}
	cout << minx << endl;
	return 0;
}