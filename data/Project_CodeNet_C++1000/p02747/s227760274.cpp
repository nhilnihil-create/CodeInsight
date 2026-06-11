#include <bits/stdc++.h>
using namespace std;

const string f = "hi";
string s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> s;
	if((int)s.size() % (int)f.size() != 0) return cout << "No" << endl, 0;
	for(int i = 0; i < s.size(); i += f.size()) {
		if(s.substr(i, f.size()) != f) return cout << "No" << endl, 0;
	}
	cout << "Yes" << endl;
	return 0;
}
