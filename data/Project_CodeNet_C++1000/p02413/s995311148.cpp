#include<stdio.h>
int main()
{
	int t=0;
	int y=0;
	int glaf[110][110]={0};

	scanf("%d %d",&t,&y);
	for(int i=0;i<t;i++)
	{
		for(int j=0;j<y;j++)
		{
			scanf("%d",&glaf[i][j]);
		}
	}

	for(int ii=0;ii<t;ii++)
	{
		for(int jj=0;jj<y;jj++)
		{
			glaf[ii][y]+=glaf[ii][jj];
		}
	}
	
	for(int iii=0;iii<y;iii++)
	{
		for(int jjj=0;jjj<t;jjj++)
		{
			glaf[t][iii]+=glaf[jjj][iii];
		}
	}

	for(int a=0;a<y;a++)
	{
		glaf[t][y]+=glaf[t][a];
	}

	for(int iiii=0;iiii<t+1;iiii++)
	{
		for(int jjjj=0;jjjj<y+1;jjjj++)
		{
			printf("%d",glaf[iiii][jjjj]);
			if(jjjj!=y) printf(" ");
		}
		printf("\n");
	}
	return 0;
}