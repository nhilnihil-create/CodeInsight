#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;
const int N = 2e5 + 3;
int a[N], b[N];
priority_queue <pair <int,int> > pq;
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}

	for(int i = 1; i <= n; i++)
	{
		cin >> b[i];
		if(b[i] < a[i])
			return cout << -1, 0;
		else if(b[i] > a[i])
			pq.push({b[i], i});
		
	}
	b[0] = b[n], b[n + 1] = b[1];
	int ans = 0;
	while(pq.size() > 0)
	{
		int i = pq.top().se;
		pq.pop();
		if(b[i] < b[i + 1] + b[i - 1])
			return cout << -1, 0;

		int tmp = (b[i + 1] + b[i - 1]);
		int step = (b[i] - a[i])/tmp;
		if(step == 0)
			return cout << -1, 0;
		ans += step;
		b[i] -= step * tmp;
		b[0] = b[n];
		b[n + 1] = b[1];

		if(b[i] > a[i])
			pq.push({b[i], i});
	}
	cout << ans;
}