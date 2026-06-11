#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <iomanip>

using namespace std;

int main(){
#ifdef CIN
	ifstream cin("input.txt");
	ofstream cout("output.txt");
#endif

	int a, b;
	int d, r;
	double f;

	cin >> a >> b;

	d = a / b;
	r = a % b;

	f = (double)a / (double)b;

	cout << d << " " << r << " " << fixed << setprecision(15) << f << endl;
	
	return 0;
}