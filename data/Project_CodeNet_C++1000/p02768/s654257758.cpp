#include<bits/stdc++.h>
using namespace std;
long long fac[200005];
long long mod = 1000000007;
long long F(int n){
	long long&ret = fac[n];
	if(~ret) return ret;
	if(n<=1) return 1;
	return ret = (n*F(n-1))%mod;
}
long long multi(long long a,long long b){
	if(b==0) return 1;
	if(b==1) return a;
	long long ret = multi(a,b/2);
	ret*=ret;
	ret%=mod;
	if(b%2) ret*=a;
	return ret%mod;
}
long long C(long long a,long long b){
	long long ret = 1;
	for(long long i=a; i>=a-b+1; i--){
		ret*=i;
		ret%=mod;
	}
	long long down = F(b);
	return (ret*multi(down,mod-2))%mod;
}
int main(){
	memset(fac,-1,sizeof(fac));
	long long n,a,b;
	cin>>n>>a>>b;
	long long ret = multi(2,n);
	ret--;
	ret-=(C(n,a)+C(n,b))%mod;
	if(ret<0) ret+=mod;
	cout<<ret;
}