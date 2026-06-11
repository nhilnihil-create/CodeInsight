#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
int main(){
	double r;
	cin >> r;
	cout << fixed <<setprecision(10) << r*r*3.141592653589 << " " << 2 * r*3.141592653589 << endl;
	return 0;
}
