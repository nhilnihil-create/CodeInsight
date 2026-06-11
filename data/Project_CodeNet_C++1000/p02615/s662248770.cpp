#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	long long n, ans,a;
	a = 0;
	cin >> n;
	long long* k = new long long[n];
	for (long long i = 0; i < n; i++)
	{
		cin >> k[i];
	}

	sort(k, k + n, greater<int>());
	
	if (n % 2 == 0 )
	{
		for (long long p = 0; p < n / 2; p++)
		{
			a += 2 * k[p];
		}
		ans = a - k[0];
	}
	else
	{
		for (long long q = 0; q < (n + 1) / 2; q++)
		{
			a += 2 * k[q];
		}
		ans = a - k[0] - k[(n - 1) / 2];
	}

	cout << ans;

	delete[] k;
	return 0;
}