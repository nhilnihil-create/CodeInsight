#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
	double a,b,r,f;
	long long int d;
	cin >> a >> b;
	d=(long long int)a/(long long int)b;
	r=(int)a%(int)b;
	f=a/b;
	cout << d << " " << r << " ";
	printf("%.5f\n",f);
	return 0; 
}