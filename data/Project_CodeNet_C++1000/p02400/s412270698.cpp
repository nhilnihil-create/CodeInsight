#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <iomanip>
using namespace std;

#define pi 3.141592653589

int main(){
	double r,S,R;
	cin >> r;
	S = r*r*pi;
	R = 2 * r*pi;
	cout << fixed << setprecision(5) << S << " " << R << endl;
	return 0;
}