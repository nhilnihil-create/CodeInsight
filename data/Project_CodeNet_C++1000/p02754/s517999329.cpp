#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#define pi 3.14159265358979323846264338327950
 
 
 
int main() {
	long long N, A, B, d; std::cin >> N >> A >> B;
	if (N % (A + B) > A) d = A;
	else d = N % (A + B);
	std::cout << ((N / (A + B)) * A) + d << std::endl;
 
	return 0;
}