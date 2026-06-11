#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pint = pair<int, int>;

int main() {
	int N;
	cin >> N;
	vector<ll> H(N);
	for (int i = 0; i < N; ++i) {
		cin >> H[i];
	}

	string ans = "Yes";
	ll prev = H[N - 1];
	for (int i = N - 2; i >= 0; --i) {
		if (prev > H[i]) {
			prev = H[i];
		}
		else if (prev == H[i]) {
			prev = H[i];
		}
		else {
			if (prev == H[i] - 1) {
				prev = H[i] - 1;
			}
			else {
				ans = "No";
				break;
			}
		}
	}

	cout << ans << endl;
	return 0;
}