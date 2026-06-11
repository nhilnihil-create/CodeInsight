#include <algorithm>
#include <iostream>

using namespace std;

int main() {
	string s; cin >> s;
	int n = s.length();
	cout << s << (s[n - 1] != 's' ? "s" : "es") << '\n';
	return 0;
}
