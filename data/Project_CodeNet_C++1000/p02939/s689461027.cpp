#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
typedef struct _data {
	int x;
	int y;
} data;

int  main()
{
	string s;
	cin >> s;
	vector<string> d;
	int i = 0;
	while (i < s.size())
	{
		if (s[i] == s[i + 1])
		{
			if (d.empty())
			{
				d.push_back(s.substr(i, 1));
			}
			else if (s.substr(i, 1) != d[d.size() - 1] )
			{
				d.push_back(s.substr(i,1));
			}
			else
			{
				d.push_back(s.substr(1, 2));
				i++;
			}
		}
		else if (s[i] != s[i + 1])
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
				d.push_back(s.substr(1, 2));
				i++;
			}
		}
		i++;
	}

	cout << d.size() << endl;
	return (0);
}
