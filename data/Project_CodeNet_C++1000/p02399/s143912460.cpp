#include<iostream>
#include<iomanip>
using namespace std;

int main(){
	int a, b;
	cin >> a >> b;
	int d = a / b;
	int r = a % b;
	double A = a;
	double B = b;
	double f = A / B;
	//http://minus9d.hatenablog.com/entry/20120528/1338213396
	cout << d << ' ' << r << ' ' << fixed << setprecision(6) << f << endl;
	return 0;
}