#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

int main(){
	double r,pai,s,l;
	pai = 3.141592653589793
		;
	cin >> r;
	s = r * r * pai;
	l = 2 * r * pai;
	printf("%f %f\n",s,l);
	return 0;
}