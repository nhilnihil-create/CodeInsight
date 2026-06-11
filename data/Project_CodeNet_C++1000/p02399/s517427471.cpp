#include <stdio.h>
#include <iostream>
using namespace std;

int main(){

	int a,b;
	double f;

	cin >> a >> b;

	f =(double)a/b;
	printf("%d %d %lf\n",a/b, a%b, f);

	return 0;
}