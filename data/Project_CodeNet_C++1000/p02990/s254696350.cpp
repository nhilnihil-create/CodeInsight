#include <iostream>

const int mod = 1000000007;

long long power(long long b, int p)
{
	long long ans = 1;
	while (p)
	{
		if (p % 2)
			ans = (ans * b) % mod;
		b = (b * b) % mod;
		p /= 2;
	}
	return ans;
}

const int size = 20005;

int fact[size]{ 1, 1 };

int df[size]{ 1, 1 };

void Compute()
{
	for (int i = 2; i < size; ++i)
	{
		fact[i] = (fact[i - 1] * static_cast<long long>(i)) % mod;
		df[i] = power(fact[i], mod - 2);
	}
}

long long ncr(int n, int r)
{
	if (r > n)
		return 0;
	return (((static_cast<long long>(fact[n]) * df[n - r]) % mod) * df[r]) % mod;
}

int main()
{
	Compute();
	int n, k;
	std::cin >> n >> k;
	for (int i = 1; i <= k; ++i)
		std::cout << (ncr(k - 1, i - 1) * ncr(n - k + 1, i)) % mod << '\n';
	return 0;
}