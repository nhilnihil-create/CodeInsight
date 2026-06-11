#include <iostream>
#include<string>

using namespace std;


int main() {
	char a, b, c, d;
	cin >> a >> b >> c >> d;
	string ans = "No";
	if (a == b) {
		if (c == d && c != a) {
			ans = "Yes";
		}
	}
	if (a == c) {
		if (b == d && b != a) {
			ans = "Yes";
		}
	}
	if (a == d) {
		if (b == c && a != b) {
			ans = "Yes";
		}
	}
	cout << ans;
}