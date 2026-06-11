#include<bits/stdc++.h>
using namespace std;
const long long N=2e5+10;
long long a[N],b[N];
long long n,x,y;
int main(){
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++){
		scanf("%lld%lld",&x,&y);
		a[i]=x+y;
		b[i]=x-y;
	}
	sort(a+1,a+1+n);
	sort(b+1,b+1+n);
	printf("%lld",max(a[n]-a[1],b[n]-b[1]));
	return 0;
}