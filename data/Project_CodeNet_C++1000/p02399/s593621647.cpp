#include<iostream>
#include<cstdio>
using namespace std;	

int main(){
	int a, b;
	cin >> a >> b;
	int d = a / b;
	int r = a % b;
	double f = 1.0 * a / b;
	printf("%d %d %.8f", d, r, f);

	return 0;
}