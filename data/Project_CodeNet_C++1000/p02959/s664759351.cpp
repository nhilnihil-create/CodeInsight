#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define int long long
int32_t main()
{


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int mon[n + 1], hero[n];
	for (int i = 0; i <= n; i++)
	{
		cin >> mon[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> hero[i];
	}
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (hero[i] <= mon[i])
		{

			sum += hero[i];
		}
		else
		{
			sum += mon[i];
			hero[i] -= mon[i];
			if (mon[i + 1] >= hero[i])
			{
				sum += hero[i];
				mon[i + 1] -= hero[i];
			}
			else
			{
				sum += mon[i + 1];
				mon[i + 1] = 0;
			}
		}
	}
	cout << sum;
}