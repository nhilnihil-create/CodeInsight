#include<stdio.h>

int main()
{
	int h, a;
	
	scanf("%d %d", &h, &a);
	
	int ans = h % a;
	
	if(ans != 0){
		printf("%d\n", (h/a) + 1);
	}else{
		printf("%d\n", h/a);
	}
}