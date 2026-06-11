#include <iostream>

int main() {
	int n, m;
	std::cin >> n >> m;
	int num = n / (m * 2 + 1);
	if (n % (m * 2 + 1))
		num++;
	/*if (!num)
		num = 1;*/
	std::cout << num << std::endl;
}
