
#include<iostream>
using namespace std;


int main()
{
	int n, i, j;
	int b[1000] = { 0 };
	int f[1000] = { 0 };
	int r[1000] = { 0 };
	int v[1000] = { 0 };
	int A[3][10] = { 0 };
	int B[3][10] = { 0 };
	int C[3][10] = { 0 };
	int D[3][10] = { 0 };

	cin >> n;

	for (i = 0; i < n; i++)
	{
		cin >> b[i] >> f[i] >> r[i] >> v[i];

		if (b[i] == 1)
		{
			for (j = 0; j < 3; j++)
			{
				if (f[i] == j+1)
				{
					for (int k = 0; k < 10; k++)
					{
						if (r[i] == k+1)
						{
							A[j][k] += v[i];
						}
					}
				}
			}
		}
		if (b[i] == 2)
		{
			for (j = 0; j < 3; j++)
			{
				if (f[i] == j + 1)
				{
					for (int k = 0; k < 10; k++)
					{
						if (r[i] == k+1)
						{
							B[j][k] += v[i];
						}
					}
				}
			}
		}
		if (b[i] == 3)
		{
			for (j = 0; j < 3; j++)
			{
				if (f[i] == j + 1)
				{
					for (int k = 0; k < 10; k++)
					{
						if (r[i] == k+1)
						{
							C[j][k] += v[i];
						}
					}
				}
			}
		}
		if (b[i] == 4)
		{
			for (j = 0; j < 3; j++)
			{
				if (f[i] == j + 1)
				{
					for (int k = 0; k < 10; k++)
					{
						if (r[i] == k+1)
						{
							D[j][k] += v[i];
						}
					}
				}
			}
		}
	}

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 10; j++)
		{
			cout << " " << A[i][j];
		}
		cout << endl;
	}
	for (i = 0; i < 20; i++)
	{
		cout << "#";
	}
	cout << endl;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 10; j++)
		{
			cout << " " << B[i][j];
		}
		cout << endl;
	}
	for (i = 0; i < 20; i++)
	{
		cout << "#";
	}
	cout << endl;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 10; j++)
		{
			cout << " " << C[i][j];
		}
		cout << endl;
	}
	for (i = 0; i < 20; i++)
	{
		cout << "#";
	}
	cout << endl;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 10; j++)
		{
			cout << " " << D[i][j];
		}
		cout << endl;
	}

	return 0;
}