#include<cstdio>
#include<algorithm>
using namespace std;
int h[100001];
int main(void)
{
	int n,mx=1000000001,flg=0,i;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&h[i]);
	}
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
	if(flg==0){
		printf("Yes\n");
	}
	else{
		printf("No\n");
	}
	return 0;
}
