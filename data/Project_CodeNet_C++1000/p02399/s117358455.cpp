#include <iostream>
#include <stdio.h>
using namespace std;

int main(void){
	int a,b,d,r;
	double f;
	cin >> a >> b ;

	d = a / b;
	r = a % b;
	f = (double)a / (double)b;

	cout << d << " " << r << " ";
	printf("%.5lf\n",f);
	return 0;
}