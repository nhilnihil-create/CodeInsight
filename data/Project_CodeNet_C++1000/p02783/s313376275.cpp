#include <stdio.h>

int main(){
	
	int a, b, ans;
	scanf("%d %d", &a, &b);
	ans = a/b;
	(a%b == 0) ? printf("%d", ans) : printf("%d", ans + 1);
	
	
	return 0;
}