#include <iostream>
#include <algorithm>
#include <set>

int main() {
	int n;
	std::cin >> n;

	std::set<int> seti;
	int a[200010];
	for (int i = 0; i < n; ++i)
	{
		std::cin >> a[i];
		seti.insert(a[i]);
	}

	if (seti.size() == n)
		std::cout << "YES";
	else
		std::cout << "NO";

}