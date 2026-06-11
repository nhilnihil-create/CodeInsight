#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

#define MAX 256

int main(void){
	
	int n, x;

	scanf("%d", &n);

	int a[n];
	
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}

	for (int i = 0; i < n; i++){
		for (int j = 0; j < n - 1 - i; j++){
			x = a[j];
			a[j] = a[j + 1];
			a[j + 1] = x;
		}
	}

	printf("%d", a[0]);
	for (int i = 1; i < n; i++){
		printf(" %d", a[i]);
	}
	printf("\n");
	return 0;
}