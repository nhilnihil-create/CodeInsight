#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>


int main()
{
	int i,j,k;
	int n,m;
	int a[10]={0}; //押された回数
	int b[10]={0,5,3,3,3,3,3,4,3,4}; //割り算	 
	int c; //押されたボタン
	char d[5][10]={
	{'0',' ','c','f','i','l','o','s','v','z'},
	{'0','.','a','d','g','j','m','p','t','w'},
	{'0',',','b','e','h','k','n','q','u','x'},
	{'0','!','0','0','0','0','0','r','0','y'},
	{'0','?','0','0','0','0','0','0','0','0'}};
	char e[1025];
	
	scanf("%d",&n);

	for(i=0;i<n;i++)
	{
		scanf("%s",e);
		c=0;
		for(j=0;j<strlen(e);j++)
		{
			if(e[j]=='0'){
				if(c!=0)
				{
					printf("%c",d[a[c]%b[c]][c]);
					a[c]=0;
					c=0;
				}
			}else
			{
				if(e[j]=='1')c=1;
				else if(e[j]=='2')c=2;
				else if(e[j]=='3')c=3;
				else if(e[j]=='4')c=4;
				else if(e[j]=='5')c=5;
				else if(e[j]=='6')c=6;
				else if(e[j]=='7')c=7;
				else if(e[j]=='8')c=8;
				else if(e[j]=='9')c=9;
				a[c]++;
			}
		}
		printf("\n");
	}

	return 0;
}