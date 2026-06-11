#include<stdio.h>

int main()
{
	int h1, m1, h2, m2, k;
	scanf("%d %d %d %d %d", &h1, &m1, &h2, &m2, &k);
	
	int hr = h2 - h1;
	int min = m2 - m1;
	int res = hr * 60 + min - k;
	printf("%d", res);		
	
	return 0;
}