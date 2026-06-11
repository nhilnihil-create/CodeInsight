#define _USE_MATH_DEFINES

#include <iostream>	//cin, cout
#include <vector>	//vector
#include <algorithm> //sort,min,max,count
#include <string>	//string,getline
#include <ios>		//fixed
#include <iomanip>	//setprecision
#include <utility> //swap
#include <cstdlib>	//abs(int)
#include <cmath>	//sqrt,ceil,M_PI, pow
#include <sstream>	//stringstream,getline
#include <numeric>	//gcd
#include <deque>	//deque

using namespace std;

int main() {

	int a;
	string S;
	cin >> a >> S;

	if (a < 3200) {
		cout << "red" << endl;
	}
	else {
		cout << S << endl;
	}

	return 0;

}