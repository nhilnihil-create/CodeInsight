#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin >> s;
	int sz = s.size();
	bool isYes = true;
	for (int i = 1; i <= sz; i++)
	{
		if (i % 2 == 1 && s[i - 1] == 'L')
		{
			isYes = false;
			break;
		}
		else if (i % 2 == 0 && s[i - 1] == 'R')
		{
			isYes = false;
			break;
		}
	}
	if (isYes)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}

