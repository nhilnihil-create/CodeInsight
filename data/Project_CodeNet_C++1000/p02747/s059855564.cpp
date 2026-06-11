#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	string s;
	cin >> s;
	if (s.length() % 2 != 0) {
		cout << "No" << endl;
		return 0;//
	}
	for (int i = 0; i < s.length() / 2; i++) {
		char x = s.at(i * 2);
		char y = s.at(i * 2 + 1);
		if (x == 'h' && y == 'i')continue;
		else {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;

}