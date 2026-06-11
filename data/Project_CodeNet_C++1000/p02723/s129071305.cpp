#include <iostream>
using namespace std;

int main() {
	string s;
	cin >> s;
	bool ok = (s[3] == s[2] && s[4] == s[5]);
	cout << (ok ? "Yes" : "No");
}
