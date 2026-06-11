#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e2 + 5;
const int INF = 1e9 + 7;

int k;
string s;

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> k >> s;
	if (s.size() > k)
		cout << s.substr(0, k) << "...";
	else
		cout << s;
	return 0;
}
//10-09-2020 21:22:41