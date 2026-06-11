#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;

int main(void) {
	int S, W;
	scanf("%d %d", &S, &W);
	printf(S <= W ? "unsafe" : "safe");

	return 0;
}
