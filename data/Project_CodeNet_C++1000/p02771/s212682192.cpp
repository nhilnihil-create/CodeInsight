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

	int A, B, C;
	cin >> A >> B >> C;

	bool flg = false;

	if (A == B) {
		if (B != C) {
			flg = true;
		}
	}
	else {
		if (A == C || B == C) {
			flg = true;
		}
	}

	if (flg) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

	return 0;

}