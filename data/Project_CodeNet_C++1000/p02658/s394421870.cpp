#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<long long> A(N);
	bool isZero = false;
	for (int i = 0; i < N; ++i)
	{
		cin >> A[i];
		if (A[i] == 0) isZero = true;
	}

	if (isZero)
	{
		cout << "0" << endl;
		return 0;
	}

	long long ans=1;
	for (int i = 0; i < N; ++i)
	{
		if (A[i] <= 1000000000000000000 / ans) ans *= A[i];
		else
		{
			cout << "-1" << endl;
			return 0;
		}
	}
	cout << ans << endl;
}