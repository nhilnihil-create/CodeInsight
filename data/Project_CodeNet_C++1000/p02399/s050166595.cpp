#include <iostream>
#include <iomanip>
using namespace std;

int main(void){
	int a, b, d, r;
	double f;

	cin >> a >> b;

	d = a / b;
	r = a%b;
	f = static_cast<double>(a) / b;

	cout << d << " " << r << " " << fixed << setprecision(8) << f << "\n";

	return 0;
}