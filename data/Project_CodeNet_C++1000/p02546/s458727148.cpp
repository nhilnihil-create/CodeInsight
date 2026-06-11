#define _USE_MATH_DEFINES

#include <iostream>	//cin, cout
#include <vector>	//vector
#include <algorithm> //sort,min,max,count
#include <string>	//string,getline, to_string
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
constexpr long long int D_MOD = 1000000007;

int main() {

	string S;
	cin >> S;

	if (S[S.length() - 1] == 's') {
		S = S + "es";
	}
	else {
		S.push_back('s');
	}

	cout << S << endl;

	return 0;

}