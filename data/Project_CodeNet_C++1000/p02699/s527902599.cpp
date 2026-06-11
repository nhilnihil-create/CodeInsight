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
inline double Median(vector<int>& A) {

	int temp = A.size();

	sort(A.begin(), A.end());

	if (temp % 2 == 0) {
		double ans = (A[(temp / 2) - 1] + A[temp / 2]) / 2.0;
		return ans;
	}
	else {
		return A[temp / 2];
	}
}

int main() {

	int S, W;
	cin >> S >> W;

	if (S <= W) {
		cout << "unsafe" << endl;
	}
	else {
		cout << "safe" << endl;
	}

	return 0;

}