#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	long long int a,b;
	cin >>a >>b;
	cout <<a/b<<" "<<a%b;
	double c = (double)a/(double)b;
	printf(" %f\n",c);
	return 0;
}