#define _USE_MATH_DEFINES
#include<iostream>
#include<math.h>
#include<cmath>
#include <algorithm>
#include <iomanip>
#include<vector>
int DISTANCE(int p, std::vector<double> x, std::vector<double> y) {
	double result = 0.;
	if(p==0){
		std::vector<double> SUB(x.size(), 0.);
		for(unsigned int i=0;i<SUB.size();++i){
			SUB[i] = std::abs(x[i] - y[i]) ;
		}
		result = *std::max_element(SUB.begin(), SUB.end());
		std::cout << std::fixed << std::setprecision(8) << result << std::endl;
	}
	else{
		for (unsigned int i = 0; i < x.size(); ++i) {
			result += std::pow(std::abs(x[i] - y[i]) , p);
		}
		std::cout << std::fixed << std::setprecision(8) << std::pow(result, 1. / p)<<std::endl;
	}
	return 0;
}
int main(void) {
	int n;
	std::cin >> n;
	std::vector<double>x(n, 0.);
	std::vector<double>y(n, 0.);
		for (int i = 0; i <  n; ++i) {
		std::cin >> x[i];
	}for (int i = 0; i < n; ++i) {
		std::cin >> y[i];
	}
	DISTANCE(1,  x,  y);
	DISTANCE(2, x, y);
	DISTANCE(3, x, y);
	DISTANCE(0, x, y);
	//		system("pause");
	return 0;
}