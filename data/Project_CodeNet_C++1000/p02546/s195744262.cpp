#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;
	getline(cin, s);
	cout << s;
	if (s[s.size()-1]=='s') cout << "es\n";
	else cout << "s\n";
	return 0;
}