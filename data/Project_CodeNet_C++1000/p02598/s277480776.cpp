#include <bits/stdc++.h>
using namespace std;
const int N = 200003;
int n, k;
int a[N];
inline bool check(int x)
{
	long long tot = 0;
	for (int i = 1; i <= n; i+=1)
		tot += a[i] / x + (a[i] % x != 0) - 1;
	return tot <= k;
}
int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i+=1) cin >> a[i];
	int l = 1, r = 1000000001, ans = 0;
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		if (check(mid)) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	cout << ans << endl;
}
