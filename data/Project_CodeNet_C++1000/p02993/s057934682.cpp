#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
int  main()
{
	string s; cin >> s;
	rep(i, 3)
	{
		if (s[i] == s[i+1])
		{
			cout << "Bad\n"; return 0;
		}
	}
	cout << "Good\n";
	return (0);
}
