#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main(){
	double a,b,C;
	double S,L,h;
	
	cin >> a >> b >> C ;
	
	C = C * 3.14159265359 / 180;
	
	h = b*sin(C);
	L = a + b + sqrt(pow(b*cos(C)-a,2) + pow(b*sin(C),2));
	S = a * h / 2;
	printf("%f\n%f\n%f\n",S,L,h);
	return 0;
}