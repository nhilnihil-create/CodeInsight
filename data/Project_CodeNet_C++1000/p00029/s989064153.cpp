#include <bits/stdc++.h>
using namespace std;

int main()
{
	map<string, int> cnt;
	string s;
	while (cin >> s) {
		cnt[s]++;
	}
	int ma = 0, le = 0;
	string res1, res2;
	for (auto p : cnt) {
		if (p.second > ma) {
			ma = p.second;
			res1 = p.first;
		}
		if ((int)p.first.size() > le) {
			le = p.first.size();
			res2 = p.first;
		}
	}
	cout << res1 << ' ' << res2 << endl;
	return 0;
}

