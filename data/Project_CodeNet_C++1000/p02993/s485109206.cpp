#include<cstdio>
#include<cstring>
char a[20000];
int main()
{
	while(~scanf("%s",a))
	{
		int l=strlen(a);
		bool flag=1;
		for(int i=1;i<l;i++)
		{
			if(a[i]==a[i-1])
			{
				flag=0;
				break;
			}
		}
		if(flag)
			printf("Good\n");
		else
			printf("Bad\n"); 
	}
} 