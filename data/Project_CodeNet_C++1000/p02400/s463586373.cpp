#include<iostream>
#include<cstdio>
using namespace std;
double S,L,r;
int main(){
	cin>>r;
	S=r*r*3.14159265358979323846264338;
	L=2.0*r*3.14159265358979323846264338;
	printf("%f %f",S,L);
	return 0;
}