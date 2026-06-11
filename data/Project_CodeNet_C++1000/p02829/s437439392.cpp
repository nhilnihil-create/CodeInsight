#include <stdio.h>
int main(){
	int a,b;
	scanf("%d %d", &a, &b);
	if(a!=1 && b!=1){
		printf("%d", 1);
	} else if(a!=2 && b!=2){
		printf("%d", 2);
	} else {
		printf("%d", 3);
	}
	return 0;
}