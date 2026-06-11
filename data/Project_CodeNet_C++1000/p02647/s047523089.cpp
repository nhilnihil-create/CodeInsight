#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> v(n), a(n + 1);
	for (int i = 0; i < n; i++) cin >> v[i];
	while (k--)
	{
		for (int i = 0; i < n; i++)
		{
			a[max(0, i - v[i])]++;
			a[min(n, i + v[i] + 1)]--;
		}
		for (int i = 1; i < n; i++)//还原差分数组
		{
			a[i] += a[i - 1];
		}
		for (int i = 0; i < n; i++) v[i] = a[i];
		for (int i = 0; i < n + 1; i++) a[i] = 0;
		int flag = 0;
		for (int i = 0; i < n; i++)
		{
			if (v[i] != n)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0) break;//特判数组是否饱和
	}
	for (int i = 0; i < n; i++)
	{
		cout << v[i] << ' ';
	}

	return 0;
}