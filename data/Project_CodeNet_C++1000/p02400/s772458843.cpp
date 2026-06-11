#define _USE_MATH_DEFINES
#include<cmath>
#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

int main(){
	double r;
	cin >> r;

	double S, L;
	S = M_PI*r*r;
	L = M_PI*r*2;

	cout << fixed << setprecision(5);
	cout << S << " " << L<<endl;

	return 0;
}