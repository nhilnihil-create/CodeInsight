#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> W(N);
	for (int i = 0; i < N; i++) cin >> W[i];
	int ans = 100000;
	for (int T = 0; T < N - 1; T++) {
		int S1 = 0, S2 = 0;
		for (int i = 0; i < N; i++) {
			if (i <= T) S1 += W[i];
			else S2 += W[i];
		}
		ans = min(ans, abs(S1 - S2));
	}
	cout << ans << endl;
	return 0;
}