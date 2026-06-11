#include <algorithm>
#include <cmath>
#include <climits>
#include <functional>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

int main() {
	ll K, N;
	cin >> K >> N;
	vector<int> a(N), diff(N);
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < N-1; i++) {
		diff[i] = a[i + 1] - a[i];
	}
	diff[N - 1] = a[0] + K - a[N-1];

	cout << K - *(max_element(diff.begin(), diff.end())) << endl;
}