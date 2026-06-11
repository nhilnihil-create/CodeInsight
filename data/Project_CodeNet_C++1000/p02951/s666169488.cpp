#define _USE_MATH_DEFINES

#include <iostream>	//cin, cout
#include <vector>	//vector
#include <algorithm> //sort,min,max,count
#include <string>	//string,getline
#include <ios>		//fixed
#include <iomanip>	//setprecision
#include <utility> //swap
#include <cstdlib>	//abs(int)
#include <cmath>	//sqrt,ceil,M_PI, pow, sin
#include <sstream>	//stringstream,getline
#include <numeric>	//gcd
#include <deque>	//deque

using namespace std;

int main() {

	int A, B, C;
	cin >> A >> B >> C;

	int ans = C - (A - B);
	if (ans < 0) {
		ans = 0;
	}

	cout << ans << endl;

	return 0;

}