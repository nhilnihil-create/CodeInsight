#include<stdio.h>
int main(){
	int a,b,c,k,count=0;
	scanf("%d%d%d%d",&a,&b,&c,&k);
	while(a>=b){
		b=b*2;
		count++;
	}
	while(b>=c){
		c=c*2;
		count++;
	}
	if(count>k)
	printf("No");
	else
	printf("Yes");
}