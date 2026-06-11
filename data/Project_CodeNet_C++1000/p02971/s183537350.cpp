#include<cstdio>
#include<algorithm>
using namespace std;
int a[200000],b[200000];
int main(void)
{
	int i,n;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	sort(b,b+n);
	for(i=0;i<n;i++){
		if(a[i]==b[n-1]){
			printf("%d\n",b[n-2]);
		}
		else{
			printf("%d\n",b[n-1]);
		}
	}
	return 0;
}