#include<cstdio>
int main()
{
	int n,i,a[20],cnt;
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	cnt=0;
	for(i=1;i<n-1;i++){
		if(a[i-1]>=a[i]&&a[i+1]<=a[i]) cnt++;
		if(a[i-1]<=a[i]&&a[i+1]>=a[i]) cnt++;
	}
	printf("%d\n",cnt);
	return 0;
}
