#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;
	string str = s;
	reverse(str.begin(), str.end());
	bool ok = s == str;
	int n = s.size();
	str = s.substr(0, (n - 1) / 2);
	reverse(str.begin(), str.end());
	if(ok)
		ok = str == s.substr(0, (n - 1) / 2);
	str = s.substr((n + 3) / 2 - 1);
	reverse(str.begin(), str.end());
	if(ok)
		ok = str == s.substr((n + 3) / 2 - 1);
	cout << (ok ? "Yes" : "No");
}
