#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
#pragma warning (disable: 4996)

long long X, N, P[1 << 18];
long long V[1 << 18];

int main() {
	cin >> X >> N;
	for (int i = 1; i <= N; i++) { cin >> P[i]; V[P[i]] = 1; }

	long long ans = -1, minx = (1LL << 60);
	for (int i = 0; i <= 1000; i++) {
		if (V[i] == 1) continue;
		if (minx > abs(i - (int)X)) {
			minx = abs(i - (int)X);
			ans = i;
		}
	}
	cout << ans << endl;
	return 0;
}