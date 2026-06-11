#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n, m;
	while (cin >> n >> m, n)
	{
		int a[100], b[100], sa = 0, sb = 0;
		for (int i = 0;i < n;i++)
		{
			cin >> a[i];
			sa += a[i];
		}
		for (int i = 0;i < m;i++)
		{
			cin >> b[i];
			sb += b[i];
		}
		int ansa = -1, ansb = -1;
		for (int i = 0;i < n;i++)
		{
			for (int j = 0;j < m;j++)
			{
				if (sa - a[i] + b[j] == sb - b[j] + a[i])
				{
					int na = i + 1, nb = j + 1;
					if (ansa<0 || ansa + ansb>a[i] + b[j])
					{
						ansa = a[i], ansb = b[j];
					}
				}
			}
		}
		if (ansa < 0)cout << -1 << endl;
		else cout << ansa << " " << ansb << endl;
	}
}