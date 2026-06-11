#include<cstdio>
int main()
{
	int a,b;
	scanf("%d %d",&a,&b);
	if(a<=10){
		a=10-a;
		a=100*a;
		printf("%d\n",a+b);
	}
	else printf ("%d\n",b);
	return 0;
}
