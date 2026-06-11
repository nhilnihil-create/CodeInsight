#include<iostream>
#include<string>
using namespace std;
int main() {

	int n;
	int a, b, c, d;
	cin >> n;
	cin >> a;
	cin >> b;
	cin >> c;
	cin >> d;
	string s;
	cin >> s;
	int i;
	for (i = a - 1; i <= c - 1; i++) {
		if ((s[i] == '#') && (s[i + 1] == '#')) {
			cout << "No";
			return 0;
		}
	}
	for (i = b - 1; i <= d - 1; i++) {
		if ((s[i] == '#') && (s[i + 1] == '#')) {
			cout << "No";
			return 0;
		}
	}
	if (c < d) {
		cout << "Yes";
		return 0;
	}
	else {
		for (i = b - 1; i <= d - 1; i++) {
			if ((s[i - 1] == '.') && (s[i + 1] == '.') && (s[i] == '.')) {
				cout << "Yes";
				return 0;
			}
		}
		cout << "No";
		return 0;
	}
	return 0;
}