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

	string S;
	cin >> S;

	sort(S.begin(), S.end());
	S.erase(unique(S.begin(), S.end()), S.end());

	if (S.size() == 2) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

	return 0;

}