#include <vector>
#include <iostream>

using namespace std;

bool prime_check(int n, int k = 2)
{
	if (n < 2) { return false; }

	if (n < k * k) { return true; }

	if (n % k == 0) { return false; }

	return prime_check(n, k + 1);
}

int main()
{
	vector<int> P;

	while (true)
	{
		int n, Ans = 0;

		cin >> n;

		if (n == 0) { break; }

		for (int i = n + 1; i <= 2 * n; i++)
		{
			if (prime_check(i) == true)
			{
				Ans++;
			}
		}

		P.push_back(Ans);
	}

	for (int i = 0; i < P.size(); i++)
	{
		cout << P[i] << endl;
	}

	return 0;
}