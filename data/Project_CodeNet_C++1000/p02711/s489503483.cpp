#include<cstdio>
#include<iostream>
using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);
	bool ans = false;
	if (N / 100 == 7) ans = true;
	N %= 100;
	if (N / 10 == 7) ans = true;
	N %= 10;
	if (N / 1 == 7) ans = true;
	printf(ans ? "Yes" : "No");

	return 0;
}
