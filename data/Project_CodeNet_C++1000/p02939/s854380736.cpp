#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int  main()
{
	string s;
	cin >> s;
	vector<string> d;
	int i = 0;
	while (i < s.size())
	{
		if (d.empty())
		{
			d.push_back(s.substr(i, 1));
		}
		else if (s.substr(i, 1) != d[d.size() - 1] )
		{
			d.push_back(s.substr(i,1));
		}
		else if (s[i + 1] != '\0')
		{
			d.push_back(s.substr(i, 2));
			i++;
		}
		i++;
	}
	cout << d.size() << endl;
	return (0);
}
