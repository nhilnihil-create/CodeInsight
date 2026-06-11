#include <iostream>
#include <string>
using namespace std;
int main()
{
	int b;
	int f[4][3][10] = {};
	cin >> b;
	for (int i = 0; i < b; i++)
	{
		int a, c, d, e;
		cin >> a >> c >> d >> e;
		f[a-1][c-1][d-1] += e;
	}
	
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 10; k++)
			{
				cout << " " << f[i][j][k];
			}
			cout << endl;
		}
		if (i < 3)
			for (int i = 0; i < 20; i++)
			{
				cout << "#";
			}
		if (i < 3)
			cout << endl;
	}
}