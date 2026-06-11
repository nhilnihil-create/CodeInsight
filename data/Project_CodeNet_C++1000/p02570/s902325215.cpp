#include<stdio.h>
int main() {
	int D, T, S;
	scanf("%d %d %d", &D, &T, &S);
	float meterPerMinute = (float)D/T;
	if (meterPerMinute <= S)printf("Yes");
	else printf("No");
}