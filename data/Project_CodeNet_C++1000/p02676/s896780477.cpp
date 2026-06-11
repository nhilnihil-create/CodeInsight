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
	int k;
	string s;
	cin >> k >> s;
	if (s.length() <= k)
		cout << s;
	else
	{
		string ans = s.substr(0, k) + "...";
		cout << ans;
	}

}

signed main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
