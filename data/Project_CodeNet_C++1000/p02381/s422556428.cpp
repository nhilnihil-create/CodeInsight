#include "iostream"
#include "math.h"


int main()
{
	double n, ave = 0, sum = 0, dev = 0, score[1000];
	while (true) {
		std::cin >> n;
		if (n == 0) break;
		for (int i = 0; i < n; i++) {
			std::cin >> score[i];
			sum += score[i];
		}
		ave = sum / n;
		for (int i = 0; i < n; i++)
			dev += pow(score[i] - ave, 2);
		dev /= n;
		dev = sqrt(dev);
		std::cout << std::fixed << dev << std::endl;
		ave = 0;
		sum = 0;
		dev = 0;
	}
    return 0;
}