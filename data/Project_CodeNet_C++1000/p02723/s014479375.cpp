#include <iostream>
#include <vector>
using namespace std;

int main() {
	string s;
	cin >> s;
	string ans;
	if (s[2] == s[3] && s[4] == s[5]) ans = "Yes";
	else ans = "No";
	cout << ans << endl;
	return 0;
}