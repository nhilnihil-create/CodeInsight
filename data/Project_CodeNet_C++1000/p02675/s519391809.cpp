#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e2 + 5;
const int INF = 1e9 + 7;

int n;

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	map<int, string> mp;
	mp[0] = "pon";
	mp[1] = "pon";
	mp[2] = "hon";
	mp[3] = "bon";
	mp[4] = "hon";
	mp[5] = "hon";
	mp[6] = "pon";
	mp[7] = "hon";
	mp[8] = "pon";
	mp[9] = "hon";
	cout << mp[n % 10];
	return 0;
}
//10-09-2020 21:20:37