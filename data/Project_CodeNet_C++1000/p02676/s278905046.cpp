#include <bits/stdc++.h>

using namespace std;

int k;
string s;

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	
	cin >> k >> s;
	if (s.size() <= k) cout << s << '\n';
	else cout << s.substr(0, k) + "...\n";
	
	return 0;
}