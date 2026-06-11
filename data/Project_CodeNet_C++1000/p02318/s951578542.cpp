#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int table[1001][1001] = {};

int main()
{
	string a, b;
	cin >> a >> b;

	for (int i = 0; i < a.size() + 1; i++)
	{
		table[i][0] = i;
	}
	for (int j = 0; j < b.size() + 1; j++)
	{
		table[0][j] = j;
	}
	for (int i = 1; i < a.size() + 1; i++)
	{
		for (int j = 1; j < b.size() + 1; j++)
		{
			if (a[i - 1] == b[j - 1])
				table[i][j] = min({ table[i - 1][j - 1], table[i - 1][j] + 1, table[i][j - 1] + 1 });
			else
				table[i][j] = min({ table[i - 1][j - 1] + 1, table[i - 1][j] + 1, table[i][j - 1] + 1 });
		}
	}

	cout << table[a.size()][b.size()] << endl;
}