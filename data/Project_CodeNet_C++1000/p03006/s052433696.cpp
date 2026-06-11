#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

signed main(void)
{
	int n;
	cin >> n;
	vector<pair<int, int>> p;
	map<pair<int, int>, ll> diff;
	ll mx, ans;

	rep(i, n) 
	{
		int a, b; 
		cin >> a >> b;
		p.push_back(make_pair(a, b));
	}
	sort(p.begin(), p.end());
	rep(i, n - 1)
	{
		for(int j = i + 1; j < n; j++)
		{
			diff[make_pair(p[j].first - p[i].first, \
							p[j].second - p[i].second)]++;
		}
	}
	mx = 0;
	for(auto p : diff)
	{
		mx = max(mx, p.second);
	}
	ans = n - mx;	
	cout << ans << endl;	
	return 0;
}
