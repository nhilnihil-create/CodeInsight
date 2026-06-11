#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main(void)
{
	int n,a[200000],i,cnt;
	scanf("%d",&n);
	for(i=1;i<=n;i++)	scanf("%d",&a[i]);
	cnt=0;
	for(i=1;i<=n;i++){
		if(a[i]!=i-cnt)	cnt++;
	}
	if(cnt==n){
		printf("-1\n");
	}
	else	printf("%d\n",cnt);
	return 0;
}
