#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i += 2) {
		if (s.substr(i, 2) != "hi") {
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";

	return 0;
}