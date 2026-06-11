#include <bits/stdc++.h>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

int main()
{
	while (true)
	{
		int n;
		cin >> n;
		if (n == 0)
		{
			return 0;
		}
		vector<int> v(n);
		long double sum = 0;
		long double beki = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
			sum += v[i];
			beki += v[i] * v[i];
		}
		long double average = sum / n;
		long double deviation = 0;


		cout << fixed << sqrtl(beki/n - (sum/n * sum/n)) << endl;
	}

	return 0;
}