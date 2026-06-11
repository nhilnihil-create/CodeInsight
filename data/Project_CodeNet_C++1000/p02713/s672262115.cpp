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
	int K;
	std::cin >> K;
	int sum = 0;
	for (int a = 1; a <= K; ++a) {
		for (int b = a; b <= K; ++b) {
			for (int c = b; c <= K; ++c) {
				int gcd = a;
				const int same = ((a==b)?1:0) + ((b == c) ? 1 : 0);
				for (; gcd > 1; --gcd) {
					if ((a%gcd == 0) && (b%gcd == 0) && (c%gcd == 0)) {
						break;
					}
				}
				switch (same) {
				case 0:
					sum += gcd*6;
					break;
				case 1:
					sum += gcd*3;
					break;
				case 2:
					sum += gcd;
					break;
				}
			}
		}
	}
	std::cout << sum << std::endl;
	return 0;
}