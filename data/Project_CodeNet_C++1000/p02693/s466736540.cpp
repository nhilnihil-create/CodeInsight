#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <string>
#include <algorithm>
int main()
{
	int A, B, K;
	std::cin >> K >> A >> B;
	if ((A + K - 1) / K * K <= B) {
		std::cout << "OK" << std::endl;
	}
	else {
		std::cout << "NG" << std::endl;
	}
	return 0;
}