#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	string s;
	cin >> s;

	if (s[s.size() - 1] == 's')
		cout << s << "es";
	else
		cout << s << "s";

	return 0;
}