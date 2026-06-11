#include<cstdio>
#include<algorithm>
using namespace std;
int main(void)
{
	int n,a[200000],i,x=0,f=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	for(i=0;i<n;i++){
		if(a[i]==a[i+1]) f=1;
	}
	if(f==0) printf("YES\n");
	else printf("NO\n");
	return 0;
}
