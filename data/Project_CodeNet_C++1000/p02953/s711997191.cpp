#include<cstdio>
#include<algorithm>
using namespace std;
int main(void)
{
	int n,h[100000],x=0,flg=0,i,mx=1000000000;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&h[i]);
	}
	if(n==1) printf("Yes\n");
	else{
		for(i=n-1;i>=0;i--){
			if(mx>=h[i]){
				mx=h[i];
			}
			else if(mx>=h[i]-1){
				mx=h[i]-1;
			}
			else{
				flg=1;
				break;
			}
		}
		if(flg==0) printf("Yes\n");
			else printf("No\n");
	}
	return 0;
}
