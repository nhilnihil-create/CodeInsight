#include<stdio.h>
int main(){
	int h1;
	int m1;
	int h2;
	int m2;
	int k;
	int result = 0;
	int x = 0;
	int y = 0;
	scanf("%d %d %d %d %d", &h1, &m1, &h2, &m2, &k);
	x = h2 - h1;
	y = m2 - m1;
	result = (x*60) + y - k;
	printf("%d", result);
	return 0;
	
}