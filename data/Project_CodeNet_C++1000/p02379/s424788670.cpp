#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <iomanip>

using namespace std;

#define pi 3.141592653589
#define repeat(i,n) for(int i=0;i<n;i++)

int main(){
	double x[2], y[2];
	cin >> x[0] >> y[0] >> x[1] >> y[1];
	double d;
	d = sqrt((x[0] - x[1])*(x[0] - x[1]) + (y[0] - y[1])*(y[0] - y[1]));
	cout << fixed << setprecision(5) << d << endl;
	return 0;
}