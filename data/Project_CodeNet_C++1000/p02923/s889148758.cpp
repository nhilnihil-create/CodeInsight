#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <queue>

using namespace std;
using ll = long long;

int main() {
	int N;
	cin >> N;

	ll prev = 1000000000;
	int cnt = -1;
	int ans = 0;
	for (int i = 0; i < N; ++i) {
		ll H;
		cin >> H;
		if (prev >= H) {
			cnt++;
		}
		else {
			ans = max(ans, cnt);
			cnt = 0;
		}
		prev = H;
	}

	ans = max(ans, cnt);
	cout << ans << endl;
	return 0;
}
