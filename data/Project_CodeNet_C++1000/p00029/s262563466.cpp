#include<stdio.h>
#include<string.h>
int main()
{
	int c=0,r=0,n=0,max=0,most=0,p,q;
	char str[1000][32],now;
	while(scanf("%c",&now)!=EOF)
	{
		if(now==' ')
		{
			str[r][c]='\0';
			r++;
			c=0;
			n++;
		}
		else
		{
			str[r][c++]=now;
		}
	}
	str[r][c]='\0';
	for(int i=0;i<=n;i++)
	{
		int same=0,temp=strlen(str[i]);
		if(temp>max)
		{
			max=temp;
			q=i;
		}
		for(int j=i+1;j<n;j++)
		{
			if(strcmp(str[i],str[j])==0)
				same++;
		}
		if(same>most)
		{
			most=same;
			p=i;
		}
	}
	printf("%s %s\n",str[p],str[q]);
}