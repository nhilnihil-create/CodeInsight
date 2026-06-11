#include <stdio.h>
#include <string.h>
struct song{
	char name[101];
	int time;
}str[50];
int main()
{
	int k;scanf("%d",&k);
	for(int i=0;i<k;i++)
	{
		scanf("%s %d",str[i].name,&str[i].time);
	}
	char s[101];int sum=0;
	scanf("%s",s);
	for(int i=0;i<k;i++)
		if(strcmp(str[i].name,s)==0)
		{
			for(int j=i+1;j<k;j++)
			sum=sum+str[j].time;
		}
		printf("%d",sum);
		return 0;
}