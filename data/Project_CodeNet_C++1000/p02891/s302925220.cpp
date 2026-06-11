#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i < (int)(n); i++)
using ll = long long;
using namespace std;


int strr(string s, int n) {
	string ss;
	rep(i, n)ss += s;
	int cnt=0;
	for (int i = 1; i < ss.size(); i++) {
		if (ss[i - 1] == ss[i]) {
			ss[i] = '_';
			cnt++;
		}
	}
	return cnt;
}
int main() {
	string s;
	map<char, int>mp;
	ll k, cnt = 0;
	cin >> s >> k;
	ll slen = s.size();
	for (char c : s)mp[c]++;
	if (mp[s[0]] == slen) {
		cout << (slen * k) / 2 << endl;
		return 0;
	}
	ll dist = strr(s, 2) - strr(s, 1);
	cout << strr(s,1) + dist * (k - 1) << endl;
	return 0;
}
