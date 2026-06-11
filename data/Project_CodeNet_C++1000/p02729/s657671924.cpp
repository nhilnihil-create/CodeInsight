#include<stdio.h>

int main (){
	
	int a,b;
	scanf("%d %d", &a, &b);
	int i = a;
	a = 0;
	for(int j = 0; j < i; j++){
		a = a+j;
	}
	int x = b;
	b = 0;
	for(int j = 0; j < x;j++){
	b = b+j;
	}
	printf("%d", a + b);
	return 0;
}