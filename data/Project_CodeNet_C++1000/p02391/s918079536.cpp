#include<stdio.h>
int main(){
	int i,n;
	char c;
	scanf("%d%d",&i,&n);
	if(i>n)
	c='>';
	if(i<n)
	c='<';
	if(i==n)
	c='=';
	if(c!='=')
	printf("a %c b\n",c);
	else printf("a == b\n");
} 
