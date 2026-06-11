#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

const int MOD = 1000000007;

int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++) cin >> A[i];
	vector<int> x(N + 1), y(N + 1), z(N + 1);
	ll ans = 1;
	for (int i = 0; i < N; i++) {
		int cnt = 0;
		x[i + 1] = x[i];
		y[i + 1] = y[i];
		z[i + 1] = z[i];
		if (x[i] == A[i]) {
			x[i + 1]++;
			cnt++;
			if (y[i] == A[i]) cnt++;
			if (z[i] == A[i]) cnt++;
		}
		else if (y[i] == A[i]) {
			y[i + 1]++;
			cnt++;
			if (z[i] == A[i]) cnt++;
		}
		else if (z[i] == A[i]) {
			z[i + 1]++;
			cnt++;
		}
		ans *= cnt;
		ans %= MOD;
	}
	cout << ans << endl;
	return 0;
}