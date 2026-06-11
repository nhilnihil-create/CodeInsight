#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

void solve()
{
	int n, k;
	cin >> n >> k;
	
	vector<int> s(n+1, 1);
	for(int i = 0; i<k; i++)
	{
		int t;
		cin >> t;
		for(int j = 0; j<t; j++)
		{
			int tt;
			cin >> tt;
			s[tt]--;
		}
	}
	int ans = 0;
	for(int i = 1; i<=n; i++)
	{
		if(s[i] == 1)
		{
			ans++;
		}
	}
	cout << ans;
			
	
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	solve();
	return 0;
}
