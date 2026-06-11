# include <iostream>
# include <math.h>

using namespace std;


int main()
{
	long long int result=1, help;
	int N;
	cin >> N;

	long long int* A;
	A = new long long int[N];

	int L = 0;

	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
		if (A[i] == 0)
			result = 0;
	}
	

	if (result != 0)
	{
		for (int i = 0; i < N; i++)
		{
			result *= A[i];
			help = result;
			while (help != 0)
			{
				L++;
				help /= 10;
			}
			if(i<N-1)
				help = A[i + 1];
			while (help != 0)
			{
				L++;
				help /= 10;
			}
			if (L > 19 && i<N-1)
			{
				if (result * A[i + 1] != 1000000000000000000)
				{
					i = N;
					result = -1;
				}
			}
			L = 0;
		}
	}

	if (result > 1000000000000000000)
		cout << -1;
	else	
		cout << result;

    return 0;
}