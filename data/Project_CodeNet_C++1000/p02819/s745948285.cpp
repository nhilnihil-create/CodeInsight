#include <iostream>
using namespace std;

bool isPrime(int n)
{
	if ((n < 2) || ((n > 2) && (n % 2 == 0))) return false;

	for (int i = 3; int64_t(i) * i <= n; i += 2)
	{
		if (n % i == 0) return false;
	}

	return true;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int x; cin >> x;
	if (x != 2)
	{
		x += !(x % 2);
		while (!isPrime(x)) { x += 2; }
	}

	cout << x << '\n';
}