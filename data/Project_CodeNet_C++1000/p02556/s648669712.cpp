#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int a[maxn], b[maxn];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x, y;
		cin >> x >> y;
		a[i] = x - y;
		b[i] = x + y;
	}
	sort(a + 1, a + n + 1);
	sort(b + 1, b + n + 1);
	cout << max(a[n] - a[1], b[n] - b[1]) << endl;
	return 0;
}