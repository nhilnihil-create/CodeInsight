#include "bits/stdc++.h"

typedef long long ll;

int main()
{
	int n;
	std::cin >> n;
	std::vector<int> a(n + 1);
	std::vector<int> b(n);
	for (int i = 0; i <= n; ++i)
	{
		std::cin >> a[i];
	}
	for (int i = 0; i < n; ++i)
	{
		std::cin >> b[i];
	}
	ll count = 0;
	for (int i = 0; i < n; ++i)
	{
		int temp = std::min(a[i], b[i]);
		a[i] -= temp;
		b[i] -= temp;
		count += temp;
		temp = std::min(a[i + 1], b[i]);
		a[i + 1] -= temp;
		b[i] -= temp;
		count += temp;
	}
	std::cout << count << '\n';
	return 0;
}