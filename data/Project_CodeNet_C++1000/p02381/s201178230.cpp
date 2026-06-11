#define _USE_MATH_DEFINES
#include<iostream>
#include<math.h>
#include<cmath>
#include <iomanip>
#include<vector>
int main(void) {
	while (1) {
		int n;
		std::cin >> n;
		if (n == 0) { 
			std::cout <<  std::endl;
			break; }
		std::vector<int>s(n,0);
		for (int i = 0; i < n; ++i) {
			std::cin >> s[i];
		}
				double MEAN = 0.;
		for (int i = 0; i< n; ++i) {
			MEAN += s[i];
		}
		MEAN =MEAN/static_cast<double>(n);

		double		standard_deviation = 0.;
		for (int i = 0; i< n; ++i) {
			standard_deviation += (s[i]-MEAN)*(s[i] - MEAN);
		}
		standard_deviation=std::sqrt(standard_deviation / static_cast<double>(n));
		std::cout << std::fixed << std::setprecision(8) << standard_deviation<<std::endl;
}
	//	system("pause");
	return 0;
}