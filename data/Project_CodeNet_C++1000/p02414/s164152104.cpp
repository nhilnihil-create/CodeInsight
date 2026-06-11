#include <iostream>
#define MAX 100
using namespace std;


int main()
{
	//?????°????????????sum_table???0??§?????????
	int n, m, l;
	int A_table[MAX][MAX];
	int B_table[MAX][MAX];
	long sum_table[MAX][MAX];

	for (int i1 = 0; i1 < MAX; i1++)
	{
		for (int i2 = 0; i2 < MAX; i2++)
		{
			sum_table[i1][i2] = 0;
		}
	}

	//????´???°?????\???
	cin >> n >> m >> l;

	//A_table??¨B_table???????´??????\???
	for (int i1 = 0; i1 < n; i1++)
	{
		for (int i2 = 0; i2 < m; i2++)
		{
			cin >> A_table[i1][i2];
		}
	}

	for (int i1 = 0; i1 < m; i1++)
	{
		for (int i2 = 0; i2 < l; i2++)
		{
			cin >> B_table[i1][i2];
		}
	}

	//A_table??¨B_table??????????¨???????sum_table?????£??\
	for (int s1 = 0; s1 < n; s1++)
	{
		for (int s2 = 0; s2 < l; s2++)
		{
			for (int i = 0; i < m; i++)
			{
				sum_table[s1][s2] = sum_table[s1][s2] + (A_table[s1][i]*B_table[i][s2]);
			}
		}
	}

	//sum_table?????????
	for (int i1 = 0; i1 < n; i1++)
	{
		for (int i2 = 0; i2 < l; i2++)
		{
			if (i2 + 1 == l)
			{
				cout << sum_table[i1][i2] << '\n';
			}
			else
			{
				cout << sum_table[i1][i2] << ' ';
			}
		}
	}

	return 0;
}