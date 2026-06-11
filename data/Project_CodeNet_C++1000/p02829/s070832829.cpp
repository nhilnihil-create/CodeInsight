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

	int A, B;
	cin >> A >> B;

	switch (A + B) {
	case 3:cout << 3 << endl; break;
	case 4:cout << 2 << endl; break;
	case 5:cout << 1 << endl; break;
	}

	return 0;

}