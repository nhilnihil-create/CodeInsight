#include<cstdio>
#include<iostream>
using namespace std;

int main(void) {
	int X, Y, Z;
	scanf("%d %d %d", &X, &Y, &Z);
	swap(X, Y);
	swap(X, Z);
	printf("%d %d %d", X, Y, Z);

	return 0;
}
