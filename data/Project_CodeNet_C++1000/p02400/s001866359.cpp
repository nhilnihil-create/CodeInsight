#define _USE_MATH_DEFINES 
#include <cmath>
#include<iostream>
#include<iomanip>
#include<cstdio>

using namespace std;

int main() {
	double r;
	cin >> r;
	cout <<fixed<<setprecision(15)<< r*r*M_PI<< " " <<fixed<<setprecision(15)<< 2 * r*M_PI << endl;
}