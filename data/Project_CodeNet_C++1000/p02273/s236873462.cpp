#include <iostream>
#include <string>
#include <vector>
#include <complex>
const double pi = 3.14159265358979;
using namespace std;

int koch(complex <double> p1, complex <double> p2, int n){
	complex <double> v1, v2, q1, q2, q3;
	double norm, angle;

	if (n>0){
		v1 = (p2 - p1)/ 3.0;
		norm = abs(v1);
		angle = arg(v1)+pi/3;
		v2 = polar(norm, angle);
		q1 = p1+v1;
		q2 = q1+v2;
		q3 = q1+v1;

		koch(p1, q1, n-1);
		koch(q1, q2, n-1);
		koch(q2, q3, n-1);
		koch(q3, p2, n-1);
	}else{
		cout << fixed << real(p1) << " " << imag(p1) << endl;
	}
	return 0;
}

int main(void){
	int n;
	cin >> n;
	complex <double> p1=0, p2=100;

	koch(p1,p2,n);
	cout << fixed << real(p2) << " " << imag(p2) << endl;
	cout << endl;
	return 0;
}