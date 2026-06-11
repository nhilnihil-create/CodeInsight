#include <cstdio>
#include <algorithm>
#define maxn 200010
int a[maxn],b[maxn],n;
using namespace std;
int main(){
	int i,l,r;
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d%d",&a[i],&b[i]);
	sort(a+1,a+1+n),sort(b+1,b+1+n);
	if(n%2)l=a[(n+1)/2],r=b[(n+1)/2];
	else l=a[n/2]+a[n/2+1],r=b[n/2]+b[n/2+1];
	printf("%d\n",r-l+1);
	return 0;
}