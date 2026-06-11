#include<iostream>
#include <string>
using namespace std;

int main()
{
	int m, n;

	while (1) 
	{
		cin >> m >> n;

		if (m == 0 && n == 0)
		{
			return 0;
		}
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << "#";
			}
			cout << "\n";
		}
		cout << "\n";
	}
	return 0;
}