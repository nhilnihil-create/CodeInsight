#include <iostream>
#include <string>
using namespace std;

int main() {
	string s, t;
	int i;
	cin >> s >> t;
	for (i = 0; i < s.size(); i++) {
		if (s[i] != t[i]) {
			cout << "No\n";
			break;
		}
	}
	if (i == s.size()) {
		cout << "Yes\n";
	}
	return 0;
}