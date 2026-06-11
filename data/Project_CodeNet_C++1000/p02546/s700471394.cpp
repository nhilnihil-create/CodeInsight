// Alert!!! This program may have some NARGLE.
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define pb push_back
#define F first
#define S second
#define endl '\n'

using namespace std;

const int Mod = 1e9 + 7, Inf = 1e9;

int32_t main ()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string s;
	cin >> s;
	if (s[s.size() - 1] == 's')
		cout << s << "es";
	else
		cout << s << 's';
	return 0;
}