#include <iostream>
#include <string>
using namespace std;
int main() {
	string s;
	int n, x;
	while (cin >> s, s != "-") {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> x;
			s = s.substr(x) + s.substr(0, x);
		}
		cout << s << endl;
	}
}