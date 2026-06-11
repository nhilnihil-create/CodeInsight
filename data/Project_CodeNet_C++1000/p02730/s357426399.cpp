#include <iostream>
#include <string>
using namespace std;

bool isp(string s)
{
	for (int i = 0, j = s.length() - 1; i < j; i++, j--) if (s[i] != s[j]) return false;
	return true;
}

int main()
{
	string s;
	cin >> s;

	bool p = isp(s);
	bool q = isp(s.substr(s.length() / 2 + 1));
	if (p && q) cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}