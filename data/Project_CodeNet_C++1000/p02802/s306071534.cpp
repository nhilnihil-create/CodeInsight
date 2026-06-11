#include<cstdio>
#include<algorithm>
using namespace std;
int main(void)
{
	int n,m,p,i,j,c[100000]={0},c2=0,c3=0,flg[100000]={0};
	char s[3];
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++){
		scanf("%d %s",&p,s);
		if(flg[p]==0&&s[0]=='W') c[p]++;
		if(flg[p]==0&&s[0]=='A'){
			c2+=c[p];
			c3++;
			flg[p]=1;
		}
	}
	printf("%d %d\n",c3,c2);
	return 0;
}
