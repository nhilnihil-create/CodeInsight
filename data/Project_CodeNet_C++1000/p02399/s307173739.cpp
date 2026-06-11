# include <iostream>
# include <iomanip>

int main() {
	int a, b;
	int ans_i;
	double ans_d;
	std::cin >> a >> b;

	ans_i = a / b;
	ans_d = static_cast<double>(a) / static_cast<double>(b);
	std::cout << std::setprecision(14);
	std::cout << std::fixed;
	std::cout << ans_i << " " << a % b << " " << ans_d << std::endl;

	std::cin >> a;
	return 0;
}