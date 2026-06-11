#include <iostream>

int main() {
	long long int h;
	int n;

	std::cin >> h >> n;

	int a[100010];
	long long int sum = 0;
	for (int i = 0; i < n; ++i)
		std::cin >> a[i], sum += a[i];

	if (sum >= h)
		std::cout << "Yes";
	else
		std::cout << "No";
}