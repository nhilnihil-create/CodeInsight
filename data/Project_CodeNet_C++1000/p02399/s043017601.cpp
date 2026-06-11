#include <iostream>
#include <iomanip> 
using namespace std ;
int main () {
	int a, b, c, d;
	double e ;
	cin >> a >> b ;           
	c = a / b ;
	d = a % b ;
	e = (double)a / b ;
	cout << fixed << setprecision(5) ;
	cout << c << " " << d << " " << e << endl ;
}
