#include <iostream>

using namespace std;

constexpr long long BASE = 1000000000;
int main()
{
	int n;
	cin >> n;
	long long res = 1;
	for (int i = 0; i < n; i++)
	{
		long long temp;
		cin >> temp;
		if (res == -1 && temp != 0)
			continue;
		if (temp == 0)
		{
			res = 0;
			continue;
		}
		long long a1 = res / BASE;
		long long b1 = res % BASE;
		long long a2 = temp / BASE;
		long long b2 = temp % BASE;
		long long temp1 = ((a1 * b2 + a2 * b1) % BASE) * BASE + b1 * b2;
		long long c1 = a1 * a2 + (a1 * b2 + a2 * b1) / BASE + temp1 / BASE / BASE;
		long long c2 = temp1 % (BASE * BASE);
		if (c1 > 1 || (c1 == 1 && c2 > 0))
			res = -1;
		else
			res *= temp;
	}
	cout << res << endl;
}