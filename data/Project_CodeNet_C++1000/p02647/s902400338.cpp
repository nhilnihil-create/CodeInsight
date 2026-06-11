#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 2e5 + 5;
int a[maxn], p[maxn];
int main()
{
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	while (k--)
	{
		bool flag = true;
		memset(p, 0, sizeof(p));
		for (int i = 1; i <= n; i++)
		{
			p[max(i - a[i], 1)]++;
			if (i + a[i] + 1 <= n)
				p[i + a[i] + 1]--;
		}
		a[1] = p[1];
		for (int i = 2; i <= n; i++)
		{
			a[i] = p[i] + a[i - 1];
			if (a[i] != n)
				flag = false;
		}
		if (flag)
			break;
	}
	for (int i = 1; i <= n; i++)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}