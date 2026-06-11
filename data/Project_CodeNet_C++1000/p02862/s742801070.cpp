#include<bits/stdc++.h>
using namespace std;
long long moder = 1000000007;
long long fac(long long n){
	long long ret = 1;
	for(long long i = 1; i<=n; i++){
		ret*=i;
		ret%=moder;
	}
	return ret;
}
long long multi(long long a,long long b){
	if(b==0) return 1;
	if(b==1) return a;
	long long ret = multi(a,b/2);
	ret*=ret;
	ret%=moder;
	if(b%2) ret*=a;
	return (ret%moder);
}
long long solve(long long a,long long b){
	long long up = fac(a+b);
	long long down = fac(a)*fac(b);
	down%=moder;
	return (up*multi(down,moder-2))%moder;
}
int main(){
	long long x,y;
	cin>>x>>y;
	if(x<y) swap(x,y);
	if(x>2*y) cout<<0;
	else if(x==2*y) cout<<1;
	else{
		long long diff = x-y;
		long long fir = diff;
		x-=2*diff;
		y-=diff;
		if(x%3) cout<<0;
		else{
			long long sec = x/3;
			fir+=x/3;
			cout<<solve(fir,sec);
		}
	}
}