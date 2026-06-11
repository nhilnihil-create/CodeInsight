#include<bits/stdc++.h>
using namespace std;
long long moder = 1000000007;
long long fac[200005];
long long multi(long long a,long long b){
	if(b==0) return 1;
	if(b==1) return a;
	long long ret = multi(a,b/2);
	ret*=ret;
	ret%=moder;
	if(b%2){
		ret*=a;
		ret%=moder;
	}
	return ret;
}
long long combi(long long n,long long k){
	long long ret = 1;
	for(int i=0; i<k; i++){
		ret*=(n-i);
		ret%=moder;
	}
	return (ret*multi(fac[k],moder-2))%moder;
}
int main(){
	fac[0] = 1;
	for(int i=1; i<=200000; i++){
		fac[i] = fac[i-1]*i;
		fac[i]%=moder;
	}
	long long n,a,b;
	cin>>n>>a>>b;
	long long ret = multi(2,n);
	long long minus = (1+combi(n,a)+combi(n,b))%moder;
	ret-=minus;
	if(ret<0) ret+=moder;
	cout<<ret;
}