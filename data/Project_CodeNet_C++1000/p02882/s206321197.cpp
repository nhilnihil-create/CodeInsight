#include <iostream>
#include <vector>
#include<map>
#include<string>
#include<algorithm>
#include<sstream>
#include<cmath>
#include<typeinfo>
#include<queue>
#include<iomanip>
using namespace std;
int main() {
	const double pi = 3.1415926535898;
	const double root_2 = 1.41421356237;
	int a,b,x;
	cin >> a >> b >> x;
	int capacity = a * a * b - x;
	double deg ;
	if (capacity * 2 < a * a * b) {
		deg = (atan(double(2*capacity) / double(a*a*a))*180.0)/pi;
	}
	else {
		deg= 90.0-((atan(double(2 * x) / double(b* b * a)) * 180.0) / pi);
	}
	cout <<fixed<<setprecision(15)<< deg;
}