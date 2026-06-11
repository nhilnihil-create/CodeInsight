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
	vector <int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	cout << v[n / 2 ] - v[n / 2 - 1 ];
}