#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define inf 1e9
#define mod 1000000007
#define ff first
#define ss second

int ans = inf;
int n, m, x;
int cost[15];
int arr[15][15];

bool check()
{
	for (int i = 0; i < m; i++)
	{
		int sum = 0;
		for (int j = 0; j < n; j++)
		{
			sum += arr[j][i];
		}
		if (sum < x)
			return false;
	}
	return true;
}

int calculate(int temp)
{
	int score[m];
	memset(score, 0, sizeof(score));
	int c = 0;
	int cnt = 0;
	while (temp)
	{
		if (temp & 1)
		{
			for (int i = 0; i < m; i++)
				score[i] += arr[cnt][i];
			c += cost[cnt];
		}
		cnt++;
		temp = temp >> 1;
	}
	bool yes = true;
	for (int i = 0; i < m; i++)
	{
		if (score[i] < x)
			yes = false;
	}
	if (yes)
		return c;
	else
		return inf;
}


void solve()
{
	cin >> n >> m >> x;


	for (int i = 0; i < n; i++)
	{
		cin >> cost[i];
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}
	if (check() == false)
	{
		cout << -1 << "\n";
		return;
	}

	for (int i = 1; i < (1 << n); i++)
	{
		int temp = calculate(i);
		ans = min(ans, temp);
	}
	cout << ans << "\n";
}

signed main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
