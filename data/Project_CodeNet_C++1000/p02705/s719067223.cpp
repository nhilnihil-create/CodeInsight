#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <string>
#include <algorithm>
#include <iomanip>
static const double PI = 3.14159265359;
int main()
{
	double R;
	std::cin >> R;
	std::cout << std::fixed << std::setprecision(3) << 2 * PI * R << std::endl;
	return 0;
}