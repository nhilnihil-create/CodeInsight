#include<cstdio>
#include<cstring>

const int N=12,INF=0x3f3f3f3f;
int g[N][N],n;

void minz(int &a,int b) { if(a>b) a=b; }

int main()
{
	int i,j,k,x,sum,cn;
	scanf("%d",&n);
	while(n) {
		memset(g,0x3f,sizeof(g));
		cn=0;
		for(i=0;i<n;i++) {
			scanf("%d%d%d",&j,&k,&x);
			if(j>cn) cn=j;
			if(k>cn) cn=k;
			g[j][k]=g[k][j]=x;
		}
		for(i=0;i<=cn;i++) g[i][i]=0;
		for(k=0;k<=cn;k++)
			for(i=0;i<=cn;i++) for(j=0;j<=cn;j++)
				minz(g[i][j],g[i][k]+g[k][j]);
		x=INF;
		for(i=0;i<=cn;i++) {
			sum=g[i][0];
			for(j=1;j<=cn;j++) if(g[i][j]<INF) sum+=g[i][j];
			if(sum<x) k=i,x=sum;
		}
		printf("%d %d\n",k,x);
		scanf("%d",&n);
	}
	return 0;
}
