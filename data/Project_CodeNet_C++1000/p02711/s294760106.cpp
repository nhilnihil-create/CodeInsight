#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int a = n % 10;
	int b = (n - a) % 100 / 10;
	int c = (n - a) / 100;
	if(a == 7 || b == 7 || c == 7){
		printf("Yes");
	}
	else {
		printf("No\n");
	}
	return 0;
}