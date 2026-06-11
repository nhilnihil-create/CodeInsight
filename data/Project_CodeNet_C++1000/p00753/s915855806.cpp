#include <iostream>
using namespace std;

#define Max 250000
int prime[Max] = {};

int main()
{
	for (int i = 2; i < Max; i++)
	{
		prime[i] = 1;
	}
	for (int i = 2; i < Max; i++)
	{
		if (prime[i] == 0) continue;
		for (int j = i + i; j < Max; j += i)
		{
			prime[j] = 0;
		}
	}
	for (int i = 2; i < Max; i++)
	{
		prime[i] = prime[i] + prime[i - 1];
	}

	int n;
	while (cin >> n, n)
	{
		cout << prime[n * 2] - prime[n] << endl;
	}

	return 0;
}