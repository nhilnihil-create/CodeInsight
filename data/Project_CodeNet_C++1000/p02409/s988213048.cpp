#include<iostream>

using namespace std;

int data1[4][3][10] = {};

int main()
{
	int n, b, f, r, v;
	int i, j, k;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> b >> f >> r >> v;
		data1[b - 1][f - 1][r - 1] += v;
	}
	//
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 3; j++)
		{
			for (k = 0; k < 10; k++)
			{
				if (data1[i][j][k] != 0)
				{
					cout << " " << data1[i][j][k];
				}
				else
				{
					cout << " 0";
				}
			}
			cout << endl;
		}
		if (i != 3)
		{
			cout << "####################" << endl;
		}
	}
	return 0;
}