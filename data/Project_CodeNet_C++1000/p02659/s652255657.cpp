#include<iostream>

int main() {
	long long A;
	double B;
	std::cin >> A >> B;
	
	long long LLB = B * 100 + 0.5;
	long long answer = A * LLB / 100;
	std::cout << answer << std::endl;
	return 0;
}