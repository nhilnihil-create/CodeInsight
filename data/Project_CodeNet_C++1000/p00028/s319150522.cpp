#include <iostream>

using namespace std;

int main()
{
	int N, A[101], i = 0, max = 0;

	for (int i = 0; i < 100; i++) { A[i] = 0; }

	while (cin >> N)
	{
		i++;

		A[N]++;
	}

	for (int j = 1; j <= 100; j++)
	{
		if (A[j] > max) { max = A[j]; }
	}

	for (int j = 1; j <= 100; j++)
	{
		if (A[j] == max) { cout << j << endl; }
	}

	return 0;
}