#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,a,b;
int main(){
	cin>>n>>a>>b;
	if(a>b)swap(a,b);
	if(a==b)puts("0");
	else if((b-a)%2==0)printf("%lld\n",(b-a)/2);
	else{
		LL ans=0;
		ans=min(n-a,b-1);
		LL b1=b;LL a1=a;
		b-=a;a=1;ans=min(ans,(b-a)/2+a1);
		a1+=(n-b1+1);LL tmp=n-b1+1;
		b1=n;ans=min(ans,(b1-a1)/2+tmp);
		cout<<ans<<endl;
	} 
}
	