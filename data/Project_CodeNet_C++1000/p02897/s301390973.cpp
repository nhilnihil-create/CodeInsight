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

	int N;
	cin >> N;

	double ans = 0;

	if (N % 2 == 0) {
		cout << "0.5000000000" << endl;
	}
	else {
		ans = ((N + 1) / 2.0) / N;
		cout << fixed << setprecision(15) << ans << endl;
	}

	return 0;

}