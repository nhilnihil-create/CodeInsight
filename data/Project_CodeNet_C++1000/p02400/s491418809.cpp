#include <iostream>
#include <iomanip>
using namespace std;


int main() {
	double r;
	cin >> r;
	double pi = 3.141592653589;
	double L = 2 * r * pi;
	double S = r * r * pi;
	cout << fixed << setprecision(12) << S << " " << L << endl;
	return 0;
}