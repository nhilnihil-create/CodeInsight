#include<bits/stdc++.h>
using namespace std;
int main() {
	string s; cin >> s;
	if(s[0] == '>') s = '<' + s;
	if(s[s.size() - 1] == '<') s = s + '>';

	vector<long long> sl;
	char prev = s[0];
	int cnt = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if(s[i] == prev) cnt++;
		else {
			sl.push_back(cnt);
			cnt = 1;
			prev = s[i];
		}
	}
	sl.push_back(cnt);

	long long res = 0;
	for (int i = 0; i < sl.size(); i+=2)
	{
		long long a = max(sl[i], sl[i+1]);
		long long b = min(sl[i], sl[i+1]) - 1;
//		cout << sl[i] << endl;
//		cout << sl[i+1] << endl;
		res += a * (a + 1) / 2;
		res += b * (b + 1) / 2;
	}
//	cout << s << endl;
	cout << res << endl;

	return 0;
}
