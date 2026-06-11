#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int n, sum = 0;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		sum += a[i];
	}
	int ans = sum, p = 0;
	for (int i = 0; i < n - 1; ++i)
	{
		p += a[i];
		sum -= a[i];
		ans = min(ans, abs(p - sum));
	}
	cout << ans << '\n';
	return 0;
}