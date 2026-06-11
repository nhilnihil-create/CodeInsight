#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<long long> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	for (int i = 0; i < n; i++)
	{
		if (a[i] == 0)
		{
			cout << 0 << endl;
			return 0;
		}
	}

	signed long long all = 1;
	long long b = 1e18;

	for (int i = 0; i < n; i++)
	{
		if (a[i] > b / all)
		{
			cout << -1 << endl;
			return 0;
		}
		all *= a[i];
	}

	cout << all << endl;

	return 0;
}