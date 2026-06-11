#include <iostream>	//cin, cout
#include <vector>	//vector
#include <algorithm> //sort,min,max
#include <string>	//string
#include <ios>		//fixed
#include <iomanip>	//setprecision
#include <utility> //swap
#include <cstdlib>	//abs(int)
#include <cmath>	//sqrt
#include <sstream>	//stringstream,getline
#include <cmath>	//ceil

using namespace std;

int main() {

	string S;
	cin >> S;

	if (isupper(S[0])) {
		cout << "A" << endl;
	}
	else {
		cout << "a" << endl;
	}

	return 0;

}