#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
#include<math.h>
#include<stdio.h>


int main()
{
	std::string n, k;
	std::cin >> n >> k;
	int kosuu = 0;
	for (int i = 0; i < n.size(); i++) {
		if (n[i] != k[i])
		{
			kosuu++;
		}
	}std::cout << kosuu << std::endl;
}