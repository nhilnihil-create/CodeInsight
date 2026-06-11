#include<bits/stdc++.h>
using namespace std;

#define testcases int t; cin>>t; while(t--)
#define int long long
const int MOD =  1e9 + 7;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

int32_t main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	FASTIO;

	int n;
	cin >> n;

	vector<int> v(n + 1);

	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j += i)
		{
			v[j]++;
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) ans += i * v[i];

	cout << ans;

}