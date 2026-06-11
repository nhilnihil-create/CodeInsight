#include <iostream>
#include <vector>
using namespace std;

int main() {
	long long n, k;
	cin >> n >> k;
	vector<int> A(n);
	for (int i = 0; i < n; i++) {
		cin >> A[i];
		A[i]--;
	}
	int a, b;
	vector<int> x(n);
	vector<int> order(n, -1);
	for (int i = 0, y = 0; ; i++) {
		if (order[y] != -1) {
			a = order[y];
			b = i;
			break;
		}
		order[y] = i;
		x[i] = y;
		y = A[y];
	}
	const int t = b - a;

	int ans;
	if (k < a) ans = x[k] + 1;
	else {
		k -= a;
		ans = x[a + k % t] + 1;
	}
	cout << ans << endl;
	return 0;
}