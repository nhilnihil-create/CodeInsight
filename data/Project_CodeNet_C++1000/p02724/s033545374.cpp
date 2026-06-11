#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

int main(void) {
	int X;
	int ans = 0;
	scanf("%d", &X);
	ans += X / 500 * 1000;
	X %= 500;
	ans += X / 5 * 5;
	X %= 5;

	printf("%d", ans);

	return 0;
}
