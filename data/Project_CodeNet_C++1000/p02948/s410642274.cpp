#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n);i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;
const int MAX = 100100;

signed main(void)
{
	int n, m;
	cin >> n >> m;
	vector<int> vec[MAX];
	priority_queue<int> pq;
	rep(i, n) 
	{
		int a, b;
		cin >> a >> b;
		vec[a].push_back(b);
	}
	ll ans = 0;
	for(int i = 1; i <= m; i++)
	{
		rep(j, vec[i].size())
		{
			pq.push(vec[i][j]);
		}
		if (pq.size() == 0) continue;
		ans += pq.top(); pq.pop(); 
	}
	cout << ans << endl;
	return 0;
}
