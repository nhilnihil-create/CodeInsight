#include <iostream>
#define _USE_MATH_DEFINES
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <math.h>
using namespace std;

int main()
{
	int N;
	std::cin >> N;
	string s;
	vector<string> S;
	for (int i = 0; i < N; i++) {
		std::cin >> s;
		S.push_back(s);
	}

	std::sort(S.begin(), S.end());
	S.erase(std::unique(S.begin(), S.end()), S.end());

	std::cout << S.size() << std::endl;
	
	return 0;
}

	
