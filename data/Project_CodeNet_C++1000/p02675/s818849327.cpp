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
#include <cmath>	//ceil

using namespace std;

int main() {

	int N;
	cin >> N;

	N = N % 10;
	string ans;

	switch (N) {
	case 0: ans = "pon"; break;
	case 1: ans = "pon"; break;
	case 2: ans = "hon"; break;
	case 3: ans = "bon"; break;
	case 4: ans = "hon"; break;
	case 5: ans = "hon"; break;
	case 6: ans = "pon"; break;
	case 7: ans = "hon"; break;
	case 8: ans = "pon"; break;
	case 9: ans = "hon"; break;
	}

	cout << ans << endl;

	return 0;

}