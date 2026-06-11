#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
	ll n, i, s = 0, j, k;
	cin >> n;
	ll a[n];
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < i; j++)
		{
			for (k = 0; k < j; k++)
			{
				if (a[i] != a[j] && a[j] != a[k] && a[i] != a[k] && (a[k] + a[j]) > a[i])
				{
					s++;
				}

			}
		}
	}
	cout<<s<<endl;
	return;



}





int main()
{
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	int t = 1;
	//cin >> t;

	while (t--)
	{
		solve();
	}


	return 0;
}
