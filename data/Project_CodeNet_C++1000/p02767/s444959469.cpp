#include <iostream>
#include <cmath>

int main()
{
	int N;
	std::cin >> N;
	double mean = 0.0;
	int X[100];
	for (int i=0; i<N; i++) {
		std::cin >> X[i];
		mean += (double)X[i];
	}
	mean /= (double)N;
	int P = (int)std::round(mean);
	int min_sum = 0;
	for (int i=0; i<N; i++) min_sum += (X[i]-P)*(X[i]-P);
	std::cout << min_sum << std::endl;
	return 0;
}
