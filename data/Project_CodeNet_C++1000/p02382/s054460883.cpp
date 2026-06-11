#include <iostream>
#include <string>
#include <iomanip>
#include <math.h>
#include <vector>

int main(int argc, char **argv){
	int n = 0;
	std::vector<int> x;
	std::vector<int> y;
	double d = 0;

	std::cin >> n;

	x.resize(n, 0);
	y.resize(n, 0);

	for(int i = 0; i < n; i++){
		std::cin >> x[i];
	}
	for(int i = 0; i < n; i++){
		std::cin >> y[i];
	}

	//p = 1
	d = 0;
	for(int i = 0; i < n; i++){
		d += abs(x[i] - y[i]);	
	}
	std::cout << std::fixed << std::setprecision(6) << d << std::endl;

	//p = 2
	d = 0;
	for(int i = 0; i < n; i++){
		d += pow(x[i] - y[i], 2.0);	
	}
	std::cout << std::fixed << std::setprecision(6) << sqrt(d) << std::endl;

	//p = 3
	d = 0;
	for(int i = 0; i < n; i++){
		d += pow(abs(x[i] - y[i]), 3.0);	
	}
	std::cout << std::fixed << std::setprecision(6) << cbrtl(d) << std::endl;


	//p = ??? 
	d = 0;
	for(int i = 0; i < n; i++){
		d = std::max<double>(abs(x[i] - y[i]), d);	
	}
	std::cout << std::fixed << std::setprecision(6) << d << std::endl;
	return 0;
}