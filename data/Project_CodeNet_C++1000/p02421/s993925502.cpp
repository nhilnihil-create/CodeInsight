#include <stdio.h>
#include <math.h>

int main()
{
	int n=0;
	int int_taro=0,int_hanako=0;
	char taro[100]={'\0'},hanako[100]={'\0'};

	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%s %s",&taro,&hanako);
		
		for(int j=0;j<100;j++)
		{
			if(taro[j]>hanako[j]){
				int_taro+=3;
				break;
			}
			else if(taro[j]<hanako[j]){
				int_hanako+=3;
				break;
			}
			else if(taro[j]=='\0'&&hanako[j]=='\0'){
				int_taro++;
				int_hanako++;
				break;
			}
		}
	}
	printf("%d %d\n",int_taro,int_hanako);

	return 0;
}