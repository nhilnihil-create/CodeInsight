#include<stdio.h>
int main()
{
	int n;
	char s[50];
	int i,c=0;
	scanf("%d %s",&n,s);
	for(i=0;i<n;i++){
		if(s[i]=='A'&&s[i+1]=='B'&&s[i+2]=='C'){
			c++;
		}
	}
	printf("%d\n",c);
	return 0;
}