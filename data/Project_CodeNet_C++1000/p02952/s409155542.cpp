#include <iostream>
#include <string>

int main()
{
	int n;
	int ans = 0;
	std::cin >> n;
	for (int i = 1; i <= n; i++)
	{
		if (std::to_string(i).length() % 2 == 1)
			++ans;
	}
	std::cout << ans << '\n';
	return 0;
}
