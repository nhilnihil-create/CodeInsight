#include<cstdio>
int main()
{
	int n,i;
	char s[100],t[100];
	scanf("%d",&n);
	scanf("%s %s",s,t);
	for(i=0;i<n;i++){
		printf("%c%c",s[i],t[i]);
	}
	printf("\n");
	return 0;
}
