#include <stdio.h>
#include <string.h>

int main(){
	int N;
	scanf("%d",&N);
	int a;
	int b;
	int c;
	a = N%10;
	b = N/10%10;
	c = N/100;
	if(a==7||b==7||c==7){
		printf("Yes");
	}else{
		printf("No");
	}
return 0;
}