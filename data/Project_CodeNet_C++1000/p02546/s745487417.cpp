#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string s; cin >> s;
	if(s[s.size() - 1] == 's') s += "es";
	else s += "s";
	cout << s << endl;

	return 0;
}