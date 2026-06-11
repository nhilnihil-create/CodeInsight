#include <iostream>
#include <cstdint>
#include <bitset>
#include <vector>
#include <thread>
#include <stack>



int main()
{
	int n;
	int ans = 0;
	std::cin >> n;
	while (ans < n) {
		ans += 1000;
	}
	std::cout << ans - n;
}