#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cctype>
#include<cmath>
#include<cstdio>
#include<set>
#include<stack>
#include<string>
#include<sstream>
#include<map>
#include<queue>
#include<vector>
using namespace std;

string rev(string s) {
	reverse(s.begin(), s.end());
	return s;
}

int main() {
	int m; cin >> m;
	while (m--) {
		string s;
		cin >> s;

		set<string> S;
		for (int i = 1; i < s.size(); i++) {
			S.insert(s.substr(0, i) + s.substr(i));
			S.insert(rev(s.substr(0, i)) + s.substr(i));
			S.insert(s.substr(0, i) + rev(s.substr(i)));
			S.insert(rev(s.substr(0, i)) + rev(s.substr(i)));
			S.insert(s.substr(i) + s.substr(0, i));
			S.insert(s.substr(i) + rev(s.substr(0, i)));
			S.insert(rev(s.substr(i)) + s.substr(0, i));
			S.insert(rev(s.substr(i)) + rev(s.substr(0, i)));
		}
		cout << S.size() << endl;
	}
	return 0;
}