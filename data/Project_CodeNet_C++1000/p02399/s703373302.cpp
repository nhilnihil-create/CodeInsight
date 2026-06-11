#include <iostream>
using namespace std;

int main(void){
	int a , b ;
	int d , r ;
	double f ;

	cin >> a >> b ;
	d = a / b ;
	r = a % b ;
	f = (double) a / b ;
	cout << d << " " << r << " " ;
	cout << fixed;
	cout.precision(5);
	cout << f << endl ;
	return 0;
}