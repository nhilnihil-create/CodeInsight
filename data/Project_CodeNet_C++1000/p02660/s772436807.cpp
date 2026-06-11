#include <iostream>
#include <cmath>
#include <vector>
#include <utility>

using namespace std;

int main()
{
	long long n;
	cin >> n;
	int res = 0;
	for (int p = 2; p <= sqrt(n) + 1; p++)
	{
		if (n % p != 0)
			continue;
		int count = 0;
		while (n % p == 0)
		{
			n /= p;
			count++;
		}
		int i = 0;
		int sum = 0;
		while (sum <= count)
			sum += ++i;
		res += i - 1;
		if (n == 1)
			break;
	}
	if (n != 1)
		res += 1;
	cout << res << endl;
	return 0;
}