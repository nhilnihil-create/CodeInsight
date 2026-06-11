#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int field[10][10000];

int main()
{
	while(true)
	{
		int C,R;
		scanf("%d%d",&R,&C);
		if(R==0&&C==0) break;
		for(int i=0;i<R;i++)
		{
			for(int j=0;j<C;j++)
			{
				scanf("%d",&field[i][j]);
			}
		}
		int ans=0;
		for(int i=0;i<(1<<R);i++)
		{
			int tmp=0;
			for(int j=0;j<C;j++)
			{
				int cnt=0;
				for(int k=0;k<R;k++)
				{
					if(field[k][j]+((i>>k)&1)==1)
					{
						cnt++;
					}
				}
				cnt=max(cnt,R-cnt);
				tmp+=cnt;
			}
			ans=max(ans,tmp);
		}
		printf("%d\n",ans);
	}
	return 0;
}