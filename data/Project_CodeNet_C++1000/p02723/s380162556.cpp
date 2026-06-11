#include <iostream>
#include <algorithm>
using namespace std;

int main ()
{
	string s;
	for (int i = 1;i <= 6;i++)
	{
		cin >> s[i];
	}
	if (s[3] == s[4] && s[5] == s[6])
	{
		cout << "Yes";
	}
	else {
		cout << "No";
	}
	return 0;
}