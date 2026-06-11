#include<iostream>
#include<stdio.h>

using namespace std;

int main() {
	long long int a, b;
	cin >> a >> b;

	 long long int d = a/b;
	 long long int r = a%b;
	double f = (double)a / b;

	printf("%lld %lld %.5f\n", d, r, f);

	return 0;
}