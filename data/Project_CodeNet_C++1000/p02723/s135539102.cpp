#define _USE_MATH_DEFINES

#include <iostream>	//cin, cout
#include <vector>	//vector
#include <algorithm> //sort,min,max,count
#include <string>	//string
#include <ios>		//fixed
#include <iomanip>	//setprecision
#include <utility> //swap
#include <cstdlib>	//abs(int)
#include <cmath>	//sqrt
#include <sstream>	//stringstream,getline
#include <cmath>	//ceil,M_PI

using namespace std;

int main() {

	string S;
	cin >> S;

	if (S[2] == S[3]) {
		if (S[4] == S[5]) {
			cout << "Yes" << endl;
			return 0;
		}
	}

	cout << "No" << endl;

	return 0;

}