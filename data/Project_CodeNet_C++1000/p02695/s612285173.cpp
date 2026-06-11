#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

int a[50], b[50], c[50], d[50];
int n, m, q;
int mx = 0;
vector<int> t;

int check()
{
	int curr = 0;
	for(int i = 0; i<q; i++)
	{
		if(t[b[i]] - t[a[i]] == c[i]) curr += d[i];
	}
	return curr;
}

void dfs(int i, int cur)
{
	if(i>=n)
	{
		mx = max(mx, check());
		return ;
	}
	for(int j = cur; j<=m; j++)
	{
		t.push_back(j);
		dfs(i+1, j);
		t.pop_back();
	}
}

void solve()
{
	cin >> n >> m >> q;
	
	for(int i = 0; i<q; i++) 
	{
		cin >> a[i] >> b[i] >> c[i] >> d[i];
		a[i]--; b[i]--;
	}
	
	dfs(0, 1);
	cout << mx << "\n";			
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	solve();
	return 0;
}
