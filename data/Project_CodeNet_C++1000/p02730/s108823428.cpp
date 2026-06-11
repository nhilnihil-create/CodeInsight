#include<algorithm>
#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

bool isKaibun(string s) {
	// cout << s << endl;
	string rev = s;
	reverse(rev.begin(), rev.end());
	return s == rev;
}

int main(void) {
	string S;
	cin >> S;
	string ans = "Yes";
	if (!isKaibun(S)) ans ="No";
	if (!isKaibun(S.substr(0, (S.length() - 1) / 2))) ans ="No";
	if (!isKaibun(S.substr(S.length() / 2 + 1, (S.length() - 1) / 2))) ans ="No";
	cout << ans << endl;

	return 0;
}
