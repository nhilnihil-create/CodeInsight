#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e2 + 5;
const int INF = 1e9 + 7;

string s, t;

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> s >> t;
	if (t.substr(0, s.size()) == s)
		cout << "Yes";
	else
		cout << "No";
	return 0;
}
//11-09-2020 09:54:04