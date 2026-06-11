#include <iostream>
#include <algorithm>
using namespace std;
int n, a[1100000], cnt, g[20];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	g[0] = 1;
	cnt = 0;
	while (true)
	{
		g[cnt + 1] = g[cnt] * 3 + 1;
		if (g[++cnt] >= n)
			break;
	}
	int ret = 0;
	for (int i = cnt - 1; i >= 0; i--)
	{
		for (int j = g[i]; j < n; j++)
		{
			int v = a[j], w = j - g[i];
			while (w >= 0 && a[w] > v)
			{
				a[w + g[i]] = a[w];
				w -= g[i];
				ret++;
			}
			a[w + g[i]] = v;
		}
	}
	cout << cnt << endl;
	for (int i = cnt - 1; i >= 0; i--)
		printf(i ? "%d " : "%d\n", g[i]);
	cout << ret << endl;
	for (int i = 0; i < n; i++)
		printf("%d\n", a[i]);
	return 0;
}

