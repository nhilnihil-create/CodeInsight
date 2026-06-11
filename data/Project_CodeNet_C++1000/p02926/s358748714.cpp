#include<bits/stdc++.h>
using namespace std;
#define int ll
#define ll long long int
#define ff first
#define ss second
#define u128 __int128
#define pb push_back
 
#define N 200010
#define MOD 1000000007


int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(20);
	int n;
	cin >> n;
	pair<int, int> po[n + 1];
	for (int i = 0; i < n; ++i)
	{
		cin >> po[i].ff >> po[i].ss;
	}

	sort(po, po + n, [](auto a, auto b){
		return atan2(a.ss, a.ff) < atan2(b.ss, b.ff);
	});

	double ans = 0;
	for(int len = 1; len <= n; ++len)
	{
		for(int i = 0; i < n; ++i)
		{
			int ref = i;
			int xsum = 0, ysum = 0;
			for(int k = 0; k < len; ++k)
			{
				xsum += po[ref + k].ff;
				ysum += po[ref + k].ss;
				if(ref + k == n - 1)
				{
					ref -= n;
				}
			}
			ans = max(ans, (double)sqrt((double)xsum * xsum + ysum * ysum));
		}
	}
	cout << fixed << ans;
	return 0;
}