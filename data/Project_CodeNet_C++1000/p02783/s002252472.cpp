#include <stdio.h>

int main(){
	
	int a, b, ans;
	scanf("%d %d", &a, &b);
	
	ans = (a+b-1)/b;
	printf("%d", ans);
	
}