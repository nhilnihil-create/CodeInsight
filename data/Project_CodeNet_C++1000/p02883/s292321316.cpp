#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mk make_pair
#define mod 1000000007
#define ll long long
#define lb lower_bound
#define ub upper_bound
#define endl "\n"
#define ff first
#define ss second
#define prec(y,x) fixed<<setprecision(y)<<x
#define inf 1e18
#define pi 3.1415926535
 
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
 
	ll n, k;
	cin >> n >> k;
	ll arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	ll food[n];
	for (int i = 0; i < n; i++)
		cin >> food[i];
	sort(arr, arr + n);
	sort(food, food + n);
	ll l = 0 ; ll r = 1e13; ll mid; mid = l + r; mid /= 2;
	int f = 1; ll ans = -1; int u = 0;
	while (f == 1)
	{
		u++;
		if (u > 100)
			break;
		if (l == r)
		{
 
			mid = l + r;
			mid /= 2;
			ll cnt = 0; int flag1 = 1;
			for (int i = 0; i < n; i++)
			{
				ll a = mid / food[n - 1 - i];
				if (arr[i] > a)
					cnt += arr[i] - a;
				if (cnt > k)
				{flag1 = 0; break;}
			}
			cnt = 0; mid++; int flag2 = 1;
			for (int i = 0; i < n; i++)
			{
				ll a = mid / food[n - 1 - i];
				if (arr[i] > a)
					cnt += arr[i] - a;
				if (cnt > k)
				{flag2 = 0; break;}
			} mid--;
			//cout << l << " " << mid << " " << r << " " << flag1 << " " << flag2 << endl;
			if (flag1 == 0 && flag2 == 0)
			{
				ans = mid;
			}
			else if (flag1 == 0 && flag2 == 1)
			{
				ans = mid + 1; break;
			}
			else
			{
				ans = mid;
			}
			break;
		}
		else
		{
			mid = l + r;
			mid /= 2;
			ll cnt = 0; int flag1 = 1;
			for (int i = 0; i < n; i++)
			{
				ll a = mid / food[n - 1 - i];
				if (arr[i] > a)
					cnt += arr[i] - a;
				if (cnt > k)
				{flag1 = 0; break;}
			}
			cnt = 0; mid++; int flag2 = 1;
			for (int i = 0; i < n; i++)
			{
				ll a = mid / food[n - 1 - i];
				if (arr[i] > a)
					cnt += arr[i] - a;
				if (cnt > k)
				{flag2 = 0; break;}
			} mid--;
			//cout << l << " " << mid << " " << r << " " << flag1 << " " << flag2 << endl;
			if (flag1 == 0 && flag2 == 0)
			{
				l = mid + 1;
			}
			else if (flag1 == 0 && flag2 == 1)
			{
				ans = mid + 1; break;
			}
			else
			{
				r = mid - 1;
			}
			//cout << l << " " << mid << " " << r << " " << flag1 << " " << flag2 << endl;
		}
	}
	cout << ans;
	return 0;
}