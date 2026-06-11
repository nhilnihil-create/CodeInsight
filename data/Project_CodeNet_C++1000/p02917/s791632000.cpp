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
	vector<int> B(N-1, 0);

	for (int i = 0; i < N-1; ++i) {
		cin >> B[i];
	}

	int ans = B[N - 1 - 1] + B[0];
	for (int i = N-1-1; i != 0; --i) {
		ans += min(B[i], B[i-1]);
	}
	cout << ans << endl;
	return 0;
}