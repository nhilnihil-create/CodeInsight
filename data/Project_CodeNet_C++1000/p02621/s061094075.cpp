#include <stdio.h>

int main (){
	int t;
	scanf("%d", &t);
	int ans = t + (t*t)+ (t*t*t);
	printf("%d", ans);
	return 0;
}