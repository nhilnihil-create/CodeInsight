#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);
	int a,b,c;
	a=n/100;
	b=((n-(a*100))/10);
	c=n-(a*100)-(b*10);
	
	if(a == 7){
		puts("Yes");
	}else if(b==7){
		puts("Yes");
	}else if(c==7){
		puts("Yes");
	}else{
		puts("No");
	}
	
	return 0;
}