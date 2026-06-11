# include <iostream>
# include <math.h>

using namespace std;

int main()
{
	long long int X, K, D;

	cin >> X >> K >> D;

	double help;

	if (X < 0)
		X = abs(X);

	help = (double)X / (double)D;

	if (X == D)
	{
		if (K % 2 == 0)
			cout << abs(X);
		else
			cout << 0;
	}
	else
	{
		if (floor(help) > K)
		{
			for (int i = 0; i < K; i++)
			{
				X -= D;
			}
		}
		else
		{
			help = floor(help);
			
			if ((K - (int)help) % 2 != 0)
			{
				help++;
			}

			for (int i = 0; i < help; i++)
			{
				X -= D;
			}
		}

		cout << abs(X) << endl;
	}

	return 0;
}