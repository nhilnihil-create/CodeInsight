#include <iostream>
#include <vector>

template <typename Func, typename Num>
Num integral(Func f, Num begin, Num end, Num d) {
	Num ret = 0;
	for (Num n = begin; n < end; n += d) {
		ret += f(n) * d;
	}
	return ret;
}

int main() {
	int n;
	std::vector<int> ans;
	
	while (std::cin >> n) {
		const int a = integral([](int x){return x*x;}, 0, 600, n);
		ans.push_back(a);
	}
	
	for (auto a : ans) {
		std::cout << a << std::endl;
	}
}