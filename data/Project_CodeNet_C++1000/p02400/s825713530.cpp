#include <iostream>
#include <cmath>
using namespace std;

int main(void){
	double r;
	double L,S;
	double P=M_PI;

	cin >> r;
	L=2*r*P;
	S=r*r*P;
	cout<<fixed;
	cout.precision(6);
	cout << S << " " << L <<endl;
	return 0;
}