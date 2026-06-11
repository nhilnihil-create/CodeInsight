#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<math.h>


#define CI cin >>
#define CO cout <<
#define E << endl;

using namespace std;

int main(void) {
	double r = 0;
	double PI = acos(-1);
	CI r;
	printf("%.7lf %.7lf",r * r * PI,2 * r * PI);
}