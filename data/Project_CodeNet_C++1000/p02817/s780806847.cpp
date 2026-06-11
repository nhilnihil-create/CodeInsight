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

	string S, T;
	cin >> S >> T;

	string ans = T + S;
	cout << ans << endl;
	
	return 0;

}