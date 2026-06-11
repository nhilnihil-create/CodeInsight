#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;

#define MAX 256

int f(int x, int y){
	if (y != 0){
		f(y, x%y);
	}
	else{
		return x;
	}
}

int main(void){

	int a, b;
	scanf("%d%d", &a, &b);
	if (a < b){
		int c = a;
		a = b;
		b = c;
	}

	printf("%d\n", f(a, b));

	return 0;
}