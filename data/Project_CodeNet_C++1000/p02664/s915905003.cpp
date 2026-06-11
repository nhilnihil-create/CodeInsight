#include <iostream>
#include <string>

using namespace std;

int main() {
	string t; cin >> t;
	for (auto c : t) cout << (c == '?' ? 'D' : c);
	cout << endl;

	return 0;
}