#include<cstdio>
#include<algorithm>
using namespace std;
int main(void)
{
	int n,k,q,a,i,y[100000]={0};
	scanf("%d%d%d",&n,&k,&q);
	for(i=0;i<q;i++){
		scanf("%d",&a);
		y[a-1]++;
	}
	for(i=0;i<n;i++){
		if(k-q+y[i]>0) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
