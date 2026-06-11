#include <iostream>
#include <vector>
#include <algorithm>

template <class T>
auto Input()
{
	T t;
	std::cin >> t;
	return t;
}

template <class T>
auto Input(int n)
{
	T v(n);
	for (auto &e : v) std::cin >> e;
	return v;
}

int main()
{
	auto n = Input<int>();
	auto v = Input<std::vector<int>>(n);
	
	std::sort(v.begin(), v.end());
	double value = v[0];
	for (int i = 1; i < n; i++) {
		value += v[i];
		value /= 2;
	}
	
	std::cout << value << std::endl;
	
	return 0;
}
