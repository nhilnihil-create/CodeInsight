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

	int n;
	cin >> n;
	int arr[n + 1] = {0};
	int q = sqrt(n); q++; q++;
	for (int i = 1; i <= q; i++)
	{
		for (int j = 1; j <= q; j++)
		{
			for (int k = 1; k <= q; k++)
			{
				int a = 0;
				a = i * i + j * j + k * k;
				a = a + i * j + j * k + k * i;
				if (a <= n)
					arr[a]++;
			}
		}
	}
	for (int i = 1; i <= n; i++)
		cout << arr[i] << endl;
	return 0;
}