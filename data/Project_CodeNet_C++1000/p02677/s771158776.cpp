#include<iostream>
#include<cmath>
#include<iomanip>

int main(void){
    int a, b, h, m;
    std::cin >> a >> b >> h >> m;

    double deg0, deg1;

    deg0 = -(30 * h + 0.5 * m);
    deg1 = - 6 * m;

    double ans;
    ans = std::sqrt(std::pow(a * std::cos(deg0 * M_PI / 180) -b * std::cos(deg1 * M_PI / 180), 2.0) +\
	std::pow(a * std::sin(deg0 * M_PI / 180) - b * std::sin(deg1 * M_PI / 180), 2.0));

    std::cout << std::fixed << std::setprecision(100) << ans << std::endl;

    return 0;
}
