#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdio>

using namespace std;


int main()
{

	long double a, b,c;
	cin >> a >> b >> c;
	c = c / 180.0 * 3.141592653589793;
	//求めるものは面積、周の長さ、高さ；
	double h,S,L;
	cout <<fixed<< a*b*sin(c)*0.5 << endl << a + b + abs(sqrt((a - b*cos(c))*(a - b*cos(c)) + (b*sin(c))*b*sin(c))) << endl << b*sin(c) << endl;
	//printf("%lf\n%lf\n%lf\n", a*b*sin(c)/2, a + b + abs(sqrt((a - b*cos(c))*(a - b*cos(c)) + (b*sin(c))*b*sin(c))), b*sin(c));
	return 0;
}