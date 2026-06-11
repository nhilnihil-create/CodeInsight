#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const double PI = 3.14159265358979;

int main() {
	int R;
	cin >> R;
	double L = 2 * R * PI;
	cout << setprecision(16) << L << endl;

	return 0;
}