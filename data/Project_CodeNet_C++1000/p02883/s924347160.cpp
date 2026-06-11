#include<bits/stdc++.h>
using namespace std;
int main() {
	long long n, k; cin >> n >> k;
	long long a[n], f[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> f[i];
	sort(a, a + n);
	sort(f, f + n, greater<int>());

	long long l = -1, r = 1e15;
	while (abs(l - r) > 1)
	{
		long long mid = (l + r) / 2;
		long long tmp = 0;
		for (int i = 0; i < n; i++)
		{
			long long tra = ((a[i] + 1) * f[i] - mid - 1) / f[i];
			tmp += max(0ll, tra);
		}
		if(tmp <= k) r = mid;
		else l = mid;
	}
	cout << r << endl;
	return 0;
}
