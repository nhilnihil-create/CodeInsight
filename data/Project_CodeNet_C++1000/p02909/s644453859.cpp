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
#include <deque>	//deque

using namespace std;

int main() {

	string S;
	cin >> S;

	switch(S[0]) {
	case 'S': cout << "Cloudy" << endl; break;
	case 'C': cout << "Rainy" << endl; break;
	case 'R': cout << "Sunny" << endl; break;
	}

	return 0;

}