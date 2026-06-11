#include <stdio.h>
int main (){
	int a,b,c;
	int x=0;
	scanf("%d %d %d",&a,&b,&c);
	while (a<=b){
		if (a%c==0){
			x=x+1;
		}
		a++;
	
	}	printf("%d",x);
	
	return 0;
}