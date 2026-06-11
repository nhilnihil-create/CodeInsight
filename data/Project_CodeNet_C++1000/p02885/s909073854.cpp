#define _USE_MATH_DEFINES

#include <iostream>	//cin, cout
#include <vector>	//vector
#include <algorithm> //sort,min,max,count
#include <string>	//string,getline
#include <ios>		//fixed
#include <iomanip>	//setprecision
#include <utility> //swap
#include <cstdlib>	//abs(int)
#include <cmath>	//sqrt
#include <sstream>	//stringstream,getline
#include <cmath>	//ceil,M_PI
#include <numeric>	//gcd

using namespace std;

int main() {

	int a, b;
	cin >> a >> b;

	if (a <= b * 2) {
		cout << 0 << endl;
		return 0;
	}

	cout << a - (b * 2) << endl;

	return 0;

}