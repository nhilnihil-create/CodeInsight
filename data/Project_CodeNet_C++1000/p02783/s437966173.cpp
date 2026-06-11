#include <stdio.h>

int main(){
	
	int a, b, ans;
	scanf("%d %d", &a, &b);
	ans = (a/b);
	if(a%b == 0){
		printf("%d", ans);
	}
	else if(a <= b){
		printf("1");
	}
	else if(b == 1){
		printf("%d", a);
	}
	else{
		printf("%d", ans + 1); 
	}
		
	return 0;
}