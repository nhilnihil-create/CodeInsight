#include<cstdio>

int main(){
	int a,b;
	scanf("%d %d", &a, &b);
	double c = a;
	double d = b;
	printf("%d %d %.8lf\n", a / b , a % b, c / d);
	return 0;
}