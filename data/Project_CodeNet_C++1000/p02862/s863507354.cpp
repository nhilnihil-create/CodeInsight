#include<bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
long long fac(long long n){
	long long ret = 1;
	for(long long i = 1; i<=n; i++){
		ret*=i;
		ret%=mod;
	}
	return ret;
}
long long ferma(long long n,long long r){
	if(r==0) return (long long)1;
	if(r==1) return n;
	long long ret = ferma(n,r/2);
	if(r%2) return (((ret*ret)%mod)*n)%mod;
	else return (ret*ret)%mod;
}
int main(){
	long long x,y;
	cin>>x>>y;
	if(x<y) swap(x,y);
	if(x>2*y) cout<<0;
	else if(x==2*y) cout<<1;
	else{
		long long one = 0;
		while(x!=y){
			one++;
			x-=2;
			y--;
		}
		if(x%3) cout<<0;
		else{
			one+=x/3;
			long long two = x/3;
			long long a = fac(one)*fac(two);
			a = ferma(a%mod,mod-2);
			cout<<(fac(one+two)*a)%mod;
		}
	}
}