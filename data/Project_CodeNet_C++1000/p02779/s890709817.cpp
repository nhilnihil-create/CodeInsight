#include<cstdio>
#include<algorithm>
using namespace std;
int main(void)
{
	int n,a[200000],i,j,flg=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	for(i=0;i<n-1;i++){
		if(a[i]==a[i+1]){
			flg=1;
		}
	}
	if(flg==1){
		printf("NO\n");
	}
	else{
		printf("YES\n");
	}
	return 0;
}