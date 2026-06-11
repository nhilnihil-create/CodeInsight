#include <iostream>
using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;

	int A[110] = {0};
	for (int i = 0; i < K; ++i)
	{
		int d;
		cin >> d;
		for (int j = 0; j < d; ++j)
		{
			int a;
			cin >> a;
			A[a - 1]++;
		}
	}

	int treated = 0;
	for (int i = 0; i < N; i++)
	{
		if (A[i] == 0)
		{
			treated++;
		}
	}

	cout << treated << endl;

	return 0;
}