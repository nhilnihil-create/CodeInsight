#include <iostream>

using namespace std;

int main()
{
	int N;

	cin >> N;

	cout << N << ':';

	while (true)
	{
		int i = 2;

		while (N >= i * i)
		{
			if (N % i == 0) { N /= i; cout << ' ' << i; goto Exit; }

			i++;
		}

		break;

	Exit:;
	}

	cout << ' ' << N << endl;

	return 0;
}