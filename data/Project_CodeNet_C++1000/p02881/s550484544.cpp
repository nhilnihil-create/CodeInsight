#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>

using namespace std;
long long INF = 1LL << 60;
int main() {
	long long N;
	cin >> N;
	int root_N = sqrt(N);
	long long ans = INF;
	for (long long i = 1; i <= root_N; i++) {
		long long j = N / i;
		if (N % i == 0) ans = min(ans, i + j - 2);
	}
	if (ans == INF) ans = N - 1;
	cout << ans << endl;
	return 0;
}