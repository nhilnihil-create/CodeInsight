#include <iostream>
using namespace std;

void test();
int sum_comb(int n);

using namespace std;

int main(void)
{
	test();
	return 0;
}

void test()
{
	int n,comb;

	while (cin >> n)
	{
		comb = sum_comb(n);

		cout << comb << endl;
	}
}

int sum_comb(int n)
{
	int a, b, c, d,cnt;
	cnt = 0;
	for (a = 0; a <= 9; a++)
	{
		for (b = 0; b <= 9; b++)
		{
			for (c = 0; c <= 9; c++)
			{
				for (d = 0; d <= 9; d++)
				{
					if ((a + b + c + d) == n)
						cnt++;
				}
			}
		}
	}
	return cnt;
}