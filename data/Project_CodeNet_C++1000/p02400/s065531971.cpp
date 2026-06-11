
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#define pi 3.14159265358979323846264338
using namespace std;

int main() {
	double r;
	cin >> r;
	cout << fixed << setprecision(8) << r*r*pi<<" "<<r*2*pi<<endl;
	return 0;
}