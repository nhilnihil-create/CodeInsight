#include <iostream>
using namespace std;

int main()
{
	long long A[100100];
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		long long a;
		cin >> a;
		if (a == 0)
		{
			cout << "0" << endl;
			return 0;
		}
		else
		{
			A[i] = a;
		}
	}

	long long ans = 1;
	for (int i = 0; i < N; i++)
	{
		if (A[i] <= 1000000000000000000 / ans)
		{
			ans *= A[i];
		}
		else
		{
			cout << "-1" << endl;
			return 0;
		}
	}

	cout << ans << endl;

	return 0;
}