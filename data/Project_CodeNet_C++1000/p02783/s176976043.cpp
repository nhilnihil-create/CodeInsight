#include<stdio.h>

int main()
{
	int n, m;
	
	scanf("%d %d", &n, &m);
	
	int sum;
	
	n % m != 0 ? sum = (n/m) + 1 : sum = n/m;
	
	printf("%d\n", sum);
}