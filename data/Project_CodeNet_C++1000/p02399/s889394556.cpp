#include <iostream>
#include <iomanip>
using namespace std;


int main() {
	int a ,b;
	cin >> a >> b ;
	int d = a/b;
	int r = a%b;
	long double f = (long double)(a)/b;
	cout << d << " " << r << " " << showpoint << fixed << setprecision(12) << f << endl;
	return 0;
}