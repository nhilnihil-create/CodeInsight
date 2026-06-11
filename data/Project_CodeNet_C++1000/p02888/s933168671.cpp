#include<bits/stdc++.h>
using namespace std;
int n, a, b, c, temp, ans, num[2005];
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)cin >> num[i];
	sort (num + 1, num + n + 1);
	for (int i = 1; i <= n - 2; i++)
	{
		for (int j = i + 1; j <= n - 1; j++)
		{
			a = num[i];
			b = num[j];
			temp = j + 1;
			while (temp <= n)
			{
				c = num[temp];
				if (a + b <= c)break;
				temp++;
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
} 