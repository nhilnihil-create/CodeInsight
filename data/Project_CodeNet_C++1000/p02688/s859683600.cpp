#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <iomanip>
#include <algorithm>

using namespace std;
using ll = long long;
using pint = pair<int, int>;

int main() {
	int N, K, d;
	cin >> N >> K;
	vector<int> s(N, 0);

	for (int i = 0; i < K; ++i) {
		int d;
		cin >> d;
		for (int j = 0; j < d; ++j) {
			int A;
			cin >> A;
			s[A-1]++;
		}
	}
	
	int ans = 0;
	for (auto ss : s) {
		if (ss == 0) {
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
