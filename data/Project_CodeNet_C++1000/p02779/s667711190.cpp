#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	int n,i,flg=0,x[200000];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&x[i]);
	}
	sort(x,x+n);
	for(i=0;i<n-1;i++){
		if(x[i]==x[i+1]){
			flg=1;
		}
	}
	if(flg==1) printf("NO\n");
	else printf("YES\n");
	return 0;
}