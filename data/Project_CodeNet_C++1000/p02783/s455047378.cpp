#include<stdio.h>

int main (){
	int a;
	int h;
	scanf("%d %d", &h, &a);
	printf("%d\n", h%a == 0? h/a : (h/a) + 1);

	return 0;
}