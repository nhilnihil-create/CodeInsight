#include <bits/stdc++.h>
using namespace std;


#define endl "\n"
#define Yes() cout << "Yes" << endl
#define No() cout << "No" << endl


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string sh; cin >> sh;
	int length = sh.size();
	for (int i = 0; i < length; ++i)
	{
		if (i % 2 == 1)
		{
			if (sh[i] != 'L' && sh[i] != 'U' && sh[i] != 'D')
			{
				cout << "No" << endl;
				return 0;
			}
		}
		else if (i % 2 == 0)
		{
			if (sh[i] != 'R' && sh[i] != 'U' && sh[i] != 'D')
			{
				cout << "No" << endl;
				return 0;
			}
		}
	}
	cout << "Yes" << endl;

}