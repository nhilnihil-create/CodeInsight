#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, m; cin >> n >> m;
	int p[m];
	string s[m];
	for (int i = 0; i < m; i++)
	{
		cin >> p[i] >> s[i];
	}
	pair<int, int> d[100100] = {};
	for (int i = 0; i < m; i++)
	{
		if(d[p[i]].second != 0) continue;
		else if(s[i] == "AC") d[p[i]].second = 1;
		else d[p[i]].first++;
	}
	int ac = 0, pena = 0;
	for (int i = 0; i <= n; i++)
	{
		if(d[i].second != 0) {
			ac++;
			pena += d[i].first;
		}
	}
	cout << ac << " " << pena << endl;
	return 0;
}
