#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
int main()
{
	string s;
	cin >> s;
	rep(i, s.size())
	{
		if (i % 2 == 0)
		{
			if (s[i] == 'L')
			{
				printf("No\n");
				return 0;
			}
		}

		if (i % 2 != 0)
		{
			if (s[i] == 'R')
			{
				
				printf("No\n");
				return 0;
			}
		}
	}
	printf("Yes\n");
	return 0;
}