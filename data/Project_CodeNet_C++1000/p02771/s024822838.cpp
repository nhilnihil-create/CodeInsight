#include<cstdio>
int main()
{
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	if(a==b&&a!=c)	printf("Yes\n");
	else if(a==c&&a!=b) printf("Yes\n");
	else if(b==c&&a!=b) printf("Yes\n");
	else printf("No\n");
	return 0;
}
