#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define inf 1e9
#define mod 1000000007
#define ff first
#define ss second

void solve()
{
	int n, k;
	cin >> n >> k;
	int reach[n + 1], arr[n + 1];

	memset(reach, -1, sizeof(reach));
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	int cnt = 0, pos = 1;
	while (true)
	{
		if (reach[pos] != -1)
			break;
		if (k == cnt)
		{
			cout << pos << "\n";
			return;
		}
		reach[pos] = cnt;
		pos = arr[pos];
		cnt++;
	}

	k -= reach[pos];
	cnt -= reach[pos];
	k = k % cnt;
	for (int i = 0; i < k; i++)
		pos = arr[pos];

	cout << pos << "\n";
}

signed main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
