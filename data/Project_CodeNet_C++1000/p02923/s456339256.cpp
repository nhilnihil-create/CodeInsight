#include<cstdio>
#include<algorithm>
using namespace std;
int main(void)
{
	int n,h[100000],i,j,cnt,x;
	scanf("%d",&n);
	for(i=0;i<n;i++)	scanf("%d",&h[i]);
	cnt=0; x=0;
	for(i=0;i<n-1;i++){
		if(h[i]>=h[i+1])	cnt++;
		else{
			if(x<cnt)	x=cnt;
			cnt=0;
		}
	}
	if(x<cnt)	x=cnt;
	printf("%d\n",x);
	return 0;
}
