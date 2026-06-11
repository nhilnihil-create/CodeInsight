#include <bits/stdc++.h>
using namespace std;
long long n,ans;
void f(int x){
	long long nn=n;
	while(nn%x==0)nn/=x;
	if(nn%x==1)++ans;	
}
int main(){
	//freopen("F.in","r",stdin); 
	//freopen("F.out","w",stdout); 
	
	scanf("%lld",&n);
	
	ans=0;
	for(long long i=1;i*i<=n;++i){
		if((n-1)%i==0){
			++ans;
			if(i*i!=n-1)++ans;
		}
	}
	
	for(long long i=2;i*i<=n;++i)if(n%i==0)f(i);
	
	printf("%lld\n",ans);
	
	return 0;
}