#include<iostream>
#include <iomanip>

using namespace std;

int main(void){
	long long int a, b;
	cin >> a >> b;

	long long int d, r;
	double f;

	d = a / b;
	r = a%b;
	f = (double)a / (double)b;

	cout << d << " " << r << " " << fixed<<setprecision(15)<< f << endl;
	return 0;
}