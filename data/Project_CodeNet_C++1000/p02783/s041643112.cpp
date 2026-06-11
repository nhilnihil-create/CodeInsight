#include <stdio.h>
int main(){
	int a,b;
	scanf("%d %d", &a, &b);
	if(a%b==0){
		printf("%d", a/b);
	} else if(a<=b){
		printf("%d", 1);
	} else{
		printf("%d", a/b + 1);
	}
	return 0;
}