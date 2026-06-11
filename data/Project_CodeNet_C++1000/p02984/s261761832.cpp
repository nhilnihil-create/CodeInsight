#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<long long> ans(n);
	for (int i = 0; i < n - 1; i++) {
		ans[n - 1] += i % 2 == 0 ? -a[i] : a[i];
	}
	ans[n - 1] += a[n - 1];
	ans[n - 1] /= 2;

	for (int i = n - 2; i >= 0; i--) {
		ans[i] = a[i] - ans[i + 1];
	}

	for (int i = 0; i < n; i++) {
		cout << ans[i] * 2 << (i == n - 1 ? "" : " ");
	}
	cout << endl;

	return 0;
}