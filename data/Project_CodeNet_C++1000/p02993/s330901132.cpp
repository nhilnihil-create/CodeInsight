#define _USE_MATH_DEFINES

#include <iostream>	//cin, cout
#include <vector>	//vector
#include <algorithm> //sort,min,max,count
#include <string>	//string,getline
#include <ios>		//fixed
#include <iomanip>	//setprecision
#include <utility> //swap, pair
#include <cstdlib>	//abs(int)
#include <cmath>	//sqrt,ceil,M_PI, pow, sin
#include <sstream>	//stringstream,getline
#include <numeric>	//gcd, accumlate
#include <deque>	//deque
#include <random>	//randam_device

using namespace std;

int main() {

	char a, b;
	cin >> a;

	for (int i = 0; i < 3; i++) {
		cin >> b;
		if (a == b) {
			cout << "Bad" << endl;
			return 0;
		}
		else {
			a = b;
		}
	}

	cout << "Good" << endl;

	return 0;

}