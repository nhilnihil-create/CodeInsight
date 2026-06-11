#include <iostream>
#include <iomanip> 
using namespace std ;
int main () {
	double  r, a, c, p ;
	cin >> r ;
	p = 3.141592653589793 ;
	a = r * r * p ;
	c = 2 * r * p ;
	cout << fixed << setprecision(10) ;
	cout << a << " " << c << endl ;
}
