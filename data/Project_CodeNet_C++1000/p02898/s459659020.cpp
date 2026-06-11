#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <queue>

using namespace std;
using ll = long long;

int main() {
	double N, K;
	cin >> N >> K;

	int ans = 0;
	for (int i = 0; i < N; ++i) {
		int h;
		cin >> h;
		if (h >= K) {
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}

