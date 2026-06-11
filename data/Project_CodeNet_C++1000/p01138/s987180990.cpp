#include <iostream>
#include <string>
#include <string.h>

using namespace std;
int table[90000];

void solve()
{
	int n;
	while(cin >> n, n)
	{
		memset(table, 0, sizeof(table));
		while(n--)
		{
			string str1, str2;
			cin >> str1 >> str2;
			int start, end;
			start = (str1[0] - '0') * 36000 + (str1[1] - '0') * 3600 + (str1[3] - '0') * 600 + (str1[4] - '0') * 60 + (str1[6] - '0') * 10 + (str1[7] - '0');
			end = (str2[0] - '0') * 36000 + (str2[1] - '0') * 3600 + (str2[3] - '0') * 600 + (str2[4] - '0') * 60 + (str2[6] - '0') * 10 + (str2[7] - '0');
			for(int i = start; i < end; ++i)
			{
				table[i]++;
			}
		}
		int max = 0;
		for(int i = 0; i < 90000; ++i)
		{
			if(max < table[i])
			{
				max = table[i];
			}
		}
		cout << max << endl;
	}
}

int main()
{
	solve();
	return(0);
}