#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int power(int a, int b)
{
	int x = 1;

	for (int i = 0; i < b; i++)
	{
		x *= a;
	}

	return x;
}

int main()
{
	int R, C;

	while (true)
	{
		cin >> R >> C;

		if (R == 0 && C == 0) { break; }

		vector<vector<int> > a(R, vector<int>(C));

		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++)
				cin >> a[i][j];

		vector<vector<int> > a2;

		int sum, sum2, max_ = 0;

		for (int i = 0; i < power(2, R); i++)
		{
			sum = 0;

			a2 = a;

			for (int j = 0; j < R; j++)
			{
				if ((i / power(2, j)) % 2 == 1)
				{
					for (int k = 0; k < C; k++)
					{
						if (a2[j][k] == 0)
						{
							a2[j][k] = 1;
						}
						else if (a2[j][k] == 1)
						{
							a2[j][k] = 0;
						}
					}
				}
			}

			for (int j = 0; j < C; j++)
			{
				sum2 = 0;

				for (int k = 0; k < R; k++)
				{
					if (a2[k][j] == 0)
					{
						sum2++;
					}
				}

				sum2 = max(sum2, R - sum2);

				sum += sum2;
			}

			max_ = max(max_, sum);
		}

		cout << max_ << endl;
	}

	return 0;
}

// Time : O ( 2 ^ (R + 1) * R * C )