#include <iostream>
#include <map>
#include <queue>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
#pragma warning (disable: 4996)

long long N, K, A[1 << 18], B[1 << 18];
map<long long, long long> Map;

int main() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> A[i]; A[i]--;
		B[i] = (B[i - 1] + A[i]) % K;
	}

	long long cnt = 0;
	for (int i = 0; i <= N; i++) {
		cnt += Map[B[i]];
		Map[B[i]]++;
		if (i >= K - 1) Map[B[i - K + 1]]--;
	}
	cout << cnt << endl;
	return 0;
}