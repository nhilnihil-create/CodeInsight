#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	int tot = 0;
	char c;
	string s;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> c;
		s += c;
		if (c == 'R') tot++;
	}
	int sum = tot;
	for (int i = 0; i < tot; i++) {
		//cout << s[i];
		if (s[i] == 'R') sum--;
	}
	cout << sum << endl;
	return 0;
}
