#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>

int main()
{
	int n;
	int ans = 1000000;
	std::cin >> n;
	std::vector<int> w(n);
	for (int i = 0; i < n; i++)
	{
		if (i == 0)
			std::cin >> w[i];
		else
		{
			int x;
			std::cin >> x;
			w[i] = w[i - 1] + x;
		}		
	}
	for (int t = 0; t < n; t++)
		ans = std::min(ans, std::abs(w[t] - w[n - 1] + w[t]));
	std::cout << ans << '\n';
	return (0);
}