#include <iostream>
#include <cmath>

int main() {
	int n, *st;
	double dev, avr, var;
	std::cin >> n;
	while (n) {
		dev = avr = var = 0.0;
		st = new int[n];
		for (int i=0; i<n; i++) {
			std::cin >> st[i];
			avr += st[i] / (double)n;
		}
		for (int i=0; i<n; i++) {
			var += (avr - st[i]) * (avr - st[i]) / n;
		}
		dev = sqrt(var);
		std::cout << dev << std::endl;
		delete[] st;
		std::cin >> n;
	}
}