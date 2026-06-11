#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 505;

int n, k, sum = 0;
int a[N];

int check(int x)
{
	int reqd = 0;
	vector<int> v;
	for(int i = 1; i <= n; i++)
	{
		int cur = a[i] % x;
		v.push_back(cur);
	}
	sort(v.begin(), v.end());
	int l = 0, r = v.size() - 1;
	int rem = 0;
	while(l <= r)
	{
		if(rem <= 0)
		{
			rem += v[l];
			reqd += v[l];
			l++;
		}
		else
		{
			rem -= (x - v[r]);
			reqd += (x - v[r]);
			r--;
		}
	}
	if(reqd > 2 * k)
		return 0;
	if(rem != 0)
		return 0;
	return 1;
}

int32_t main()
{
	IOS;
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	int ans = 1;
	for(int i = 1; i * i <= sum; i++)
	{
		if(sum % i == 0)
		{
			if(check(i))
				ans = max(ans, i);
			if(check(sum / i))
				ans = max(ans, sum / i);
		}
	}
	cout << ans;
	return 0;
}
