#include <bits/stdc++.h>

using namespace std;

const int DIM = 2e5 + 7;

#define int long long

priority_queue <pair <int, int> > q;

int a[DIM];
int b[DIM];

int n;

int lft(int pos)
{
	pos--;
	
	if(pos == 0)
		pos = n;
	
	return pos;
}

int rht(int pos)
{
	pos++;
	
	if(pos == n + 1)
		pos = 1;
	
	return pos;
}

main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	
	for(int i = 1; i <= n; i++)
	{
		cin >> b[i];
		
		if(a[i] != b[i])
			q.push({b[i], i});
	}
	
	int ans = 0;
	
	while(!q.empty())
	{
		int val = q.top().first;
		int id = q.top().second;
		
		q.pop();
		
		int dif = val - a[id];
		
		int p = b[lft(id)] + b[rht(id)];
		
		int k = dif / p;
		k = max(k, 1LL);
		
		ans += k;
		
		val -= k * p;
		
		if(val < a[id])
		{
			cout << -1;
			return 0;
		}
		
		b[id] = val;
		
		if(val != a[id])
			q.push({val, id});
	}
	
	cout << ans;
}