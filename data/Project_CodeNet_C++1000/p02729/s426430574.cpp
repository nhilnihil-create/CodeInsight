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

inline double nCr(const int n, int r) {

	if (n == 0) { return 0; }
	if (r == 0) { return 1; }
	if (r == 1) { return n; }
	if (n == r) { return 1; }

	if (r > n / 2) { r = n / 2; }

	double result = 1;
	for (double i = 1; i <= r; i++) {
		result *= (n - i + 1) / i;
	}

	return(result);
}

int main() {

	int N, M;
	cin >> N >> M;

	int ans = 0;
	if (N >= 2) {
		ans += static_cast<int>(nCr(N, 2));
	}
	if (M >= 2) {
		ans += static_cast<int>(nCr(M, 2));
	}

	cout << ans << endl;

	return 0;

}