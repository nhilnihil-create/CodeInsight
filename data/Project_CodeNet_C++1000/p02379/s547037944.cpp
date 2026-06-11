#include <iostream>
#include <complex>
 
using namespace std;
 int main(void){
 complex <double> p1,p2;
 cin >> p1.real() >> p1.imag() >> p2.real() >> p2.imag();
 double r = abs(p2-p1);
 cout << fixed<< r << endl;
 return 0;
}