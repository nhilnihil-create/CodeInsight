#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
#define PI 3.14159265
	
int main(void){
	double a,b,rad;
	double S,L,h;
	cin>>a>>b>>rad;
	rad=rad*PI/180;
	S = a*b*sin(rad)/2.0;
	L = a + b + sqrt(a*a+b*b-2*a*b*cos(rad));
	h = 2*S/a;
	cout.precision(8);
	cout<<fixed<<S<<" "<<L<<" "<<h<<endl;
	return 0;
}