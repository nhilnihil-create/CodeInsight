#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(int argc, char** argv) {
	pair<double, double> P1, P2;
	cin >> P1.first >> P1.second 
		>> P2.first >> P2.second;
	cout << fixed << setprecision(6)
		<< (double)sqrt(pow(P1.second-P2.second, 2.0)+pow(P1.first-P2.first, 2.0)) << endl;
	return 0;
}