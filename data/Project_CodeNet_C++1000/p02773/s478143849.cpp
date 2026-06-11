#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n; cin >> n;
	unordered_map<string, int> m;
	int mx = 0;
	set<string> ss;
	while(n--)
	{
		string s; 
		cin >> s;
		++m[s];
		mx = max(mx, m[s]);
	}
	for (auto it : m)
	{
		if (it.second == mx) ss.insert(it.first);
	}
	for (auto st : ss)
	{
		cout << st << endl;
	}



}
