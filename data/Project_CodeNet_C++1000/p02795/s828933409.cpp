#include<stdio.h>

int main(){
	int h,x,n;
	scanf("%d%d%d",&h,&x,&n);
	if(h>=n || x>=n) printf("1\n");
	else if(h>x){
		if(n % h == 0) printf("%d\n",n/h);
		else printf("%d\n",n/h+1);	
		
	}
	else{
		if(n % x == 0) printf("%d\n",n/x);
		else printf("%d\n",n/x+1);	
	}
	
	
	
	return 0;
}