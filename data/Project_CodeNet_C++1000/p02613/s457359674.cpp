#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long int ll;

void solve()
{
	ll n;
	cin >> n;
	string s;
	map<string, int> mp;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		mp[s]++;
	}
	cout << "AC x " << mp["AC"] << endl;
	cout << "WA x " << mp["WA"] << endl;
	cout << "TLE x " << mp["TLE"] << endl;
	cout << "RE x " << mp["RE"] << endl;


}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("1input.txt", "r", stdin);
	freopen("1output.txt", "w", stdout);
#endif

	int t = 1;
	// cin >> t;

	while (t--)
	{
		solve();
		cout << "\n";
	}

	return 0;
}