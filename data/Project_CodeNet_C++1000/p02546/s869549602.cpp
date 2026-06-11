#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin >> s;

	if (*s.rbegin() != 's')
	{
		s += 's';
	}
	else
	{
		s += "es";
	}

	cout << s << endl;

	return 0;
}