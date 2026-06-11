#include <iostream>
#include <vector>
using namespace std;

int main() {
	int k, n;
	cin >> k >> n;

	vector<int> a(n + 1);
	vector<int> b(n);
	a[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		b[i - 1] = a[i] - a[i - 1];
	}

	b[0] = k - a[n] + a[1];

	int max = 0;

	for (int i = 0; i < n; i++)
	{
		if (b[i] > max)
		{
			max = b[i];
		}
	}

	int ans = 0 - max;

	for (int i = 0; i < n; i++)
	{
		ans += b[i];
	}

	cout << ans << endl;

	return 0;
}