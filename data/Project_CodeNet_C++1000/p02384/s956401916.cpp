#include <iostream>
#include <math.h>
#include <string>
#define MEN 6
#include <iomanip>
using namespace std;


struct DICE
{
	int num;
};

int main()
{
	DICE A[MEN];
	int out[24];
	int q, x, y;
	int i = 0;

	for (int i = 0; i < MEN; i++)
	{
		cin >> A[i].num;
	}

	cin >> q;

	for (int i = 0; i < q;i++)
	{
		cin >> x >> y;

		if (x == A[0].num)
		{
			if (y == A[1].num)
			{
				out[i] = A[2].num;
			}
			else if (y == A[2].num)
			{
				out[i] = A[4].num;
			}
			else if (y == A[4].num)
			{
				out[i] = A[3].num;
			}
			else if (y == A[3].num)
			{
				out[i] = A[1].num;
			}
		}
		else if (x == A[1].num)
		{
			if (y == A[0].num)
			{
				out[i] = A[3].num;
			}
			else if (y == A[3].num)
			{
				out[i] = A[5].num;
			}
			else if (y == A[5].num)
			{
				out[i] = A[2].num;
			}
			else if (y == A[2].num)
			{
				out[i] = A[0].num;
			}
		}
		else if (x == A[2].num)
		{
			if (y == A[0].num)
			{
				out[i] = A[1].num;
			}
			else if (y == A[1].num)
			{
				out[i] = A[5].num;
			}
			else if (y == A[5].num)
			{
				out[i] = A[4].num;
			}
			else if (y == A[4].num)
			{
				out[i] = A[0].num;
			}
		}
		else if (x == A[3].num)
		{
			if (y == A[0].num)
			{
				out[i] = A[4].num;
			}
			else if (y == A[4].num)
			{
				out[i] = A[5].num;
			}
			else if (y == A[5].num)
			{
				out[i] = A[1].num;
			}
			else if (y == A[1].num)
			{
				out[i] = A[0].num;
			}
		}
		else if (x == A[4].num)
		{
			if (y == A[0].num)
			{
				out[i] = A[2].num;
			}
			else if (y == A[2].num)
			{
				out[i] = A[5].num;
			}
			else if (y == A[5].num)
			{
				out[i] = A[3].num;
			}
			else if (y == A[3].num)
			{
				out[i] = A[0].num;
			}
		}
		else if (x == A[5].num)
		{
			if (y == A[1].num)
			{
				out[i] = A[3].num;
			}
			else if (y == A[3].num)
			{
				out[i] = A[4].num;
			}
			else if (y == A[4].num)
			{
				out[i] = A[2].num;
			}
			else if (y == A[2].num)
			{
				out[i] = A[1].num;
			}
		}
	}

	for (int i = 0; i < q; i++)
	{
		cout << out[i] << endl;
	}

	return 0;
}