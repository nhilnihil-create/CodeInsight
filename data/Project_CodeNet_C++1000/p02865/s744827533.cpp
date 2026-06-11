#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <numeric>
#include <functional>
#include <stack>

int main (){
	int a;

	std::cin >> a;

	int count = 0;
	for (size_t i = 1; i <= a / 2; i++)
	{
		if (a - i != i) {
			count++;
		}
	}

	std::cout << count << std::endl;
	return 0;
}