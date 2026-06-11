#include <iostream>
#include <vector>
#include <map>
using namespace std;

const long MOD = 1'000'000'007;

int main() {
	string s; cin >> s;
	for (auto c: s) {
		if (c == '7') {
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}
