#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;
using ll = long long;
using pint = pair<int, int>;

int main() {
	int N;
	cin >> N;

	vector<int> W(N);
	for (int i = 0; i < N; ++i) {
		cin >> W[i];
	}

	int ans = 100000;
	for (int i = 0; i < N; ++i) {
		int S1 = 0;
		for (int j = 0; j <= i; ++j) {
			S1 += W[j];
		}

		int S2 = 0;
		for (int k = i+1; k < N; ++k) {
			S2 += W[k];
		}

		ans = min(ans, abs(S1 - S2));
	}

	cout << ans << endl;
	return 0;
}
