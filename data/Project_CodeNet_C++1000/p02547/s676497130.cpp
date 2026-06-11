#include<cstdio>
#include<algorithm>
using namespace std;
int main(void)
{
	int n,a,b,i,c=0,x=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d %d",&a,&b);
		if(a==b){
			c++;
			if(x<c) x=c;
		}
		if(a!=b) c=0;
	}
	if(x>=3) printf("Yes\n");
	else printf("No\n");
	return 0;
}
