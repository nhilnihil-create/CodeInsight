#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
#include <map>
#include <queue>
#define _PI (3.141592653589793)
int main()
{
	int A, B, C, K;
	std::cin >> A >> B >> C >> K;
	int remain = K;
	int sum = 0;
	if (A >= remain) {
		sum += remain;
		remain = 0;
	}
	else {
		sum += A;
		remain -= A;
	}
	if (B >= remain) {
		remain = 0;
	}
	else {
		remain -= B;
	}
	sum -= remain;
	std::cout << sum << std::endl;
	return 0;
}
