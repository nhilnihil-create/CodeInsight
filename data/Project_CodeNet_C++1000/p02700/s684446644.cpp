#include<cstdio>
int main()
{
	int a,b,c,d,x;
	scanf("%d %d %d %d",&a,&b,&c,&d);
	while(1){
		// printf("a%d-d%d  c%d-b%d\n",a,d,c,b);
		c=c-b;
		// printf("c=%d\n");
			if(c<=0){
			x=2;
			break;
		}
		a=a-d;
		// printf("a=%d\n",a);
		if(a<=0){
			x=1;
			break;
		}
	}
	if(x==1) printf("No\n");
	else printf("Yes\n");
	return 0;
}