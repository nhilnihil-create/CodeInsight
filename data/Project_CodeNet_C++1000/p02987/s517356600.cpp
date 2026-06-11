#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

string s;
int main() {
	cin >> s;
	sort(s.begin(), s.end());
	cout << (s[0]==s[1] && s[1]!=s[2] && s[2]==s[3] ? "Yes" : "No");
	return 0;
}
