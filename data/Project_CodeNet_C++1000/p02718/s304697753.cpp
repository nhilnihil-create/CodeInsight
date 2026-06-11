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
	int N, M;
	cin >> N >> M;

	double total = 0;
	vector<double> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
		total += A[i];
	}

	int cnt = 0;
	for (int i = 0; i < N; ++i) {
		if (A[i] >= total / (double)(4 * M)) {
			cnt++;
		}
	}

	cout << ((cnt >= M) ? "Yes" : "No") << endl;
	return 0;
}
