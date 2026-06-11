#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	string s;
	int q;

	cin >> s;
	cin >> q;

	string op, p;
	int a, b;

	while(q--) {
		cin >> op >> a >> b;

		if(op == "print") {
			cout << s.substr(a, b - a + 1) << endl;
		} else if(op == "reverse") {
			reverse(s.begin() + a, s.begin() + b + 1);
		} else {
			cin >> p;
			s.replace(a, b - a + 1, p);
		}
	}
}

