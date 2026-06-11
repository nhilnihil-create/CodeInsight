#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#define PI 3.1415926535
using namespace std;

int main(void){
	double a, b, rad, h, s, l;
	cin >>a >>b >>rad;
	rad*=PI/180;
	h=b*sin(rad);
	s=a*h*0.5;
	l=a+b+sqrt(pow(a, 2)+pow(b, 2)-2*a*b*cos(rad));
	cout <<fixed <<setprecision(10) <<s <<endl <<l <<endl <<h <<endl;
    return 0;
}