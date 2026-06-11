#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define int long long
int32_t main()
{


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int l, r;
	cin >> l >> r;
	if (l * r < 2019)
		cout << l*(l + 1);
	else if ((l - 1) / 2019 != (r / 2019))
	{
		cout << 0;
	}
	else
	{
		int min = LONG_MAX;
		for (int i = l; i < r; i++)
		{
			for (int j = i + 1; j <= r; j++)
			{
				if (((i * j) % 2019) < min)
				{
					min = ((i * j) % 2019);
				}
			}
		}
		cout << min;
	}
}