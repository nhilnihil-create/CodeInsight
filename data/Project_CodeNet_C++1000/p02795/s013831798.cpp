#include <stdio.h>
#include <string.h>

int main(){
	int a, b, c, ans = 0, count = 0;
	scanf("%d %d %d", &a, &b, &c);
	if(a >= b){
	do{
		ans += a;
		count++;
		}while(ans < c);
	}
	else{
		do{
			ans += b;
			count++;
		}while(ans < c);
	}
	printf("%d", count);
	return 0;
}