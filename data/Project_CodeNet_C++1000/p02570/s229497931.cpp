#pragma warning(disable:4996)
#include <stdio.h>
int main()
{
	double d, t, s;
	scanf("%lf %lf %lf", &d, &t, &s);
	if (d / s > t) printf("No");
	else printf("Yes");
}