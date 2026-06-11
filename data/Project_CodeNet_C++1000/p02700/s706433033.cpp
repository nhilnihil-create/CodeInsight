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
	
	int A, B, C, D;
	std::cin >> A >> B >> C >> D;
	int A_turn = 0;
	if (C%B == 0) {
		A_turn = C / B;
	}
	else {
		A_turn = (C / B) + 1;
	}
	int B_turn;
	if (A%D == 0) {
		B_turn = A / D;
	}
	else {
		B_turn = (A / D) + 1;
	}


	if (A_turn <= B_turn) {
		std::cout << "Yes";
	}
	else {
		std::cout << "No";
	}
	return 0;
}

	
