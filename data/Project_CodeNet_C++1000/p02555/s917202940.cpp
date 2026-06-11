#include<bits/stdc++.h>
using namespace std;
const long long p=1e9+7;
int a[10003];
signed main(){
	int n;
  cin>>n;
	if(n<3) puts("0"),exit(0);
	if(n==3) puts("1"),exit(0);
	a[3]=a[4]=a[5]=1,a[6]=2;
	for(int i=7; i<=n; i++) { a[i]=1; for(int j=3; j+3<=i; j++) a[i]+=a[j],a[i]%=p; }
	printf("%lld\n",a[n]);
	return 0;
}