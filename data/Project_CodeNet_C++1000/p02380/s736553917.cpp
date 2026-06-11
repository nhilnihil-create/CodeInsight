#include<iostream>
#include<math.h>
#define PI 3.141592/180
using namespace std;

int main()
{
	int a,b,C;
	double S,L,h;

	cin >> a >> b >>C;

	h = b * sin(C*PI);

	S = a * h / 2;

	L = sqrt((a*a)+(b*b)-(2*a*b*cos(C*PI))) + a + b;

	cout << S << ' ' << L << ' ' << h << endl ;

	return 0;
}