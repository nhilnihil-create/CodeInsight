#include <iostream>
#include <string>
#include <iomanip>
#include <math.h>
#include <vector>

#define INPUT_FROM_FILE (0)
#if INPUT_FROM_FILE
#include <fstream>
#endif

int main(int argc, char **argv){
#if INPUT_FROM_FILE
	std::ifstream ifs("test.txt");
#endif
	int n = 0;

#if INPUT_FROM_FILE
	while(ifs >> n, n != 0){
#else
	while(std::cin >> n, n != 0){
#endif
		double mean = 0;
		double sigma2 = 0;
		std::vector<int> s(n, 0);

		for(int i = 0; i < n; i++){
#if INPUT_FROM_FILE
			ifs >> s[i]; 
#else
			std::cin >> s[i]; 
#endif
			mean += s[i];
		}
		mean /= n;

		for(int i = 0; i < n; i++){
			sigma2 += pow(s[i] - mean, 2);
		}
		sigma2 /= n;
		std::cout << std::fixed << std::setprecision(5) << sqrt(sigma2) << std::endl;
	}
	return 0;
}