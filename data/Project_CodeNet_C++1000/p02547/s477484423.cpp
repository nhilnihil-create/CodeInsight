#include <bits/stdc++.h>
#include <fstream>
using namespace std;

int main()
{
//	ifstream cin("input.txt");
	int A[100][2];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cin >> A[i][j];
		}
	}
	int con = 0;
	for (int i = 0; i < n; i++)
	{
		if (A[i][0] == A[i][1])
		{
			//cout << A[i][0] << endl;
			con++;
			if (con == 3)
			{
				cout << "Yes" << endl;
				exit(0);
			}
		}
		else
		{
			con = 0;
		}
	}
	cout << "No" << endl;

	return 0;
}
