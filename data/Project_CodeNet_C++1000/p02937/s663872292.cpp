#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	string s, t;
	cin >> s;
	cin >> t;
	//-1
	set<char>ss, ts;
	for (int i = 0; i < s.length(); i++)ss.insert(s.at(i));
	for (int i = 0; i < t.length(); i++) {
		ts.insert(t.at(i));
		if(ss.count(t.at(i)))continue;
		else {
			cout << -1 << endl;
			return 0;
		}
	}
	//alphabet-indexを作る
	int ends = s.length();
	vector<vector<int>>alpex(26, vector<int>(0));
	vector<int>alpmax(26,-1);
	for (int i = 0; i < s.length(); i++) {
		int x = s.at(i) - 'a';
		alpex.at(x).push_back(i + 1);
	}
	for (int i = 0; i < 26; i++) {
		if(alpex.at(i).size()>=1)alpmax.at(i) = alpex.at(i).at(alpex.at(i).size() - 1);
	}
	for (int i = 0; i < 26; i++) {
		char x = 'a' + i;
		if (!ts.count(x))alpex.at(i).clear();
	}
	ll ans = 0;
	int ct = 0;
	for (int i = 0; i < t.length(); i++) {
		int x = t.at(i) - 'a';
		if (alpmax.at(x) <= ct) {
			ans += ends - ct;
			ct = 0;
			//cout << "Re:"<<ans << endl;
		}
		int y = upper_bound(alpex.at(x).begin(), alpex.at(x).end(), ct) - alpex.at(x).begin();
		ans += alpex.at(x).at(y) - ct;
		ct = alpex.at(x).at(y);
		//cout <<i<<":"<< ans << " ct:"<<ct<< endl;
	}
	cout << ans << endl;
}