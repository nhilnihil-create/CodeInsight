#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <functional>
#include <queue>
using namespace std;

long long N, A[1 << 19], cnt[1 << 22];
long long ans;

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int i = 1; i <= N; i++) {
		if (i - A[i] >= 0) ans += cnt[i - A[i]];
		if (i + A[i] <= 2000000) cnt[i + A[i]]++;
	}
	for (int i = 0; i <= 2000000; i++) cnt[i] = 0;
	for (int i = N; i >= 1; i--) {
		if (i + A[i] <= 2000000) ans += cnt[i + A[i]];
		if (i - A[i] >= 0) cnt[i - A[i]]++;
	}
	cout << ans / 2LL << endl;
	return 0;
}