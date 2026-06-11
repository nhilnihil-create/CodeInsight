#include<iostream>
#include<iomanip>
using namespace std;

int main(){
	double r;
	cin >> r;
	double P = 3.141592653589793;
	double S = P * r * r;
	double L = 2 * P * r;
	cout << fixed << setprecision(6) << S << ' ' << L << endl;
	return 0;
}