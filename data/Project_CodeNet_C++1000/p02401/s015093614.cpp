#include<stdio.h>
int main(void)
{
	int a,b,c,wa,sa,se,syo;
	
	scanf("%d %c %d",&a,&c,&b);
	while(c!='?'){
	if(c=='+'){
		wa=a+b;
		printf("%d\n",wa);
		scanf("%d %c %d",&a,&c,&b);
		}
	if(c=='-'){
		sa=a-b;
		printf("%d\n",sa);
		scanf("%d %c %d",&a,&c,&b);
		}
	if(c=='*'){
		se=a*b;
		printf("%d\n",se);
		scanf("%d %c %d",&a,&c,&b);
		}
	if(c=='/'){
		syo=a/b;
		printf("%d\n",syo);
		scanf("%d %c %d",&a,&c,&b);
		}
	}
	return 0;
}