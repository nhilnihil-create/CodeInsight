#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
void solve()
{
	int m, d;
	cin >> m >> d;
	int ans = 0;	
	for (int i = 1; i <= d; i++)
	{
		int x = i % 10;
		int y = i / 10 % 10;
		if (x * y <= m && x>=2 && y>=2)
			ans++;
		// cout<<i<<" ";
	}
	cout << ans;

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	


	int t;
	// cin >> t;
	t = 1;
	while (t--) solve();


	return 0;
}
