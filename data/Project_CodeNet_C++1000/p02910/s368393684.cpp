#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (i % 2 == 0) {
			if (s.at(i) == 'L') {
				cout << "No" << endl;
				return 0;
			}
		}
		else {
			if (s.at(i) == 'R') {
				cout << "No" << endl;
				return 0;
			}
		}
	}
	cout << "Yes" << endl;
}