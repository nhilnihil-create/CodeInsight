#include<stdio.h>
#include<iostream>
using namespace std;
int main() {
	int a, b, c, d,i = 0;
	scanf("%d %d", &a, &b);
	printf("%d %d %f\n", a / b, a % b, double(a) / b);
}
