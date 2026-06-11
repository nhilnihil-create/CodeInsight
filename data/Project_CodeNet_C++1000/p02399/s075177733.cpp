#include<iostream>
using namespace std;

int main(){
	int a, b, d, r;
	double a2, b2, f;
	cin >> a >> b;
	a2 = a;
	b2 = b;
	d = a / b;
	r = a % b;
	f = a2 / b2;
	printf("%d %d %.5lf", d,r,f);
	 }
	