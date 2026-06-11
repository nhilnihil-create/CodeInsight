#include <stdio.h>
int main(){
	int K=500;
	int b, c;
	scanf("%d %d", &b, &c);
	
	if(b*K >= c){
		printf("Yes");
	}else if(b*K < c){
		printf("No");
	}
	return 0;
}