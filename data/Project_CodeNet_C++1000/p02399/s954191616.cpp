#include<iostream>
#include<iomanip>
using namespace std;

int main() {
	long a,b,d,r;
	double f;
	cin >> a >> b;
	d = a/b;
	r = a%b;
	f = 1.000000000*a / b;
	cout  << d << ' ' << r << ' '<< fixed << setprecision(8) << f << endl;
}