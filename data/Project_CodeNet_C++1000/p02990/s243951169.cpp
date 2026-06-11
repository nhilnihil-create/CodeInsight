#include<bits/stdc++.h>
using namespace std;
long long moder = 1000000007;
long long fac[5005]={1};
long long multi(long long a,long long b){
	if(b==0) return 0;
	if(b==1) return a;
	long long ret = multi(a,b/2);
	ret*=ret;
	ret%=moder;
	if(b%2) ret*=a;
	return ret%moder;
}
long long F(long long n){
	long long&ret = fac[n];
	if(~ret) return ret;
	if(n<=1) return ret = 1;
	return ret = (n*F(n-1))%moder;
}
long long C(long long n,long long r){
	long long up = F(n);
	long long down = F(n-r)*F(r);
	down%=moder;
	return (up*multi(down,moder-2))%moder;
}
long long H(long long n,long long r){
	return C(n+r-1,r);
}

int main(){
	memset(fac,-1,sizeof(fac));
	long long n,k;
	cin>>n>>k;
	long long blue = k;
	long long red = n-k;
	for(long long i=1; i<=k; i++){
		long long red_wall = i-1;
		if(red_wall>red) cout<<0<<'\n';
		else{
			long long red_left = red-red_wall;
			long long blue_left = blue-i;
			cout<<(H(red_wall+2,red_left)*H(i,blue_left))%moder<<'\n';
		}
	}
}