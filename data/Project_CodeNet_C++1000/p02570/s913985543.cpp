#include<stdio.h>
int main() {
	float D, T, S;
	scanf("%f %f %f", &D, &T, &S);
	float meterPerMinute = D/T;
	if (meterPerMinute <= S)printf("Yes");
	else printf("No");
}