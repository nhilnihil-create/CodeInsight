#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	string s;
	cin >> s;
	for (int i = 0; i < s.length() - 1; i++) {
		if (s.at(i) == s.at(i + 1)) {
			cout << "Bad" << endl;
			return 0;
		}
	}
	cout << "Good" << endl;
}