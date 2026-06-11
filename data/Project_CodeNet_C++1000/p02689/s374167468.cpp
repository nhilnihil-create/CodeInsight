#include<cstdio>
#include<algorithm>
using namespace std;
int main(void)
{
	int n,m,h[100001],a,b,c[100001]={0},i,x=0;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%d",&h[i]);
	}
	for(i=1;i<=m;i++){
		scanf("%d%d",&a,&b);
		if(h[a]>h[b]) c[b]=1;
		if(h[a]<h[b]) c[a]=1;
		if(h[a]==h[b]){
			c[a]=1;
			c[b]=1;
		}
	}
	for(i=1;i<=n;i++){
		if(c[i]==0) x++;
	}
	printf("%d\n",x);
	return 0;
}
