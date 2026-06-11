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

int main() {

	vector<int> A(3);
	cin >> A[0] >> A[1] >> A[2];

	sort(A.begin(), A.end());

	cout << A[0] + A[1] << endl;

	return 0;

}