#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
	int a,b,x;
	cin >> a >> b;
	printf("%d %d %.6f\n",a/b,a%b,(double)a/b);
	return 0;
}