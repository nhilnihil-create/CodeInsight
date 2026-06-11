#define _USE_MATH_DEFINES

#include<stdio.h>
#include<iostream>
#include<iomanip>
#include<math.h>

using namespace std;

/* cout << fixed << setprecision(5); */

int main()
{	
	double S,L,r;

	cin >> r;

	S = r*r*M_PI;
	L = 2 * M_PI*r;

	cout << fixed << setprecision(5);

	cout << S << " " << L ;
	



	return 0;
}