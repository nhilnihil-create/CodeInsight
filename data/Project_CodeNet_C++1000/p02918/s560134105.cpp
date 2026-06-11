#include <bits/stdc++.h>
#include <math.h>

using namespace std;

long long inf=1000000007;

long long modpow(long long n,long long p,long long mod);

int main(){
	long long n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	long long x=0,y=0;
	long long ans=0;
	for(long long i=0;i<n;i++){
		if((i==0 && s.at(i)=='L') || (i==n-1 && s.at(n-1)=='R')) continue;

		if(s.at(i)=='R' && s.at(i+1)=='R') ans++;
		if(s.at(i)=='L' && s.at(i-1)=='L') ans++;
	}

	if(s.at(n-1)=='R') y++;
	for(long long i=0;i<n-1;i++){
		if(i==0 && s.at(i)=='L') y++;
		if(s.at(i)=='R' && s.at(i+1)=='L') x++;
	}

	ans+=min(x,k)*2;
	k-=x;
	ans+=min(y,max(k,(long long)0));
	cout<<min(ans,n-1)<<endl;

	return 0;
}

long long modpow(long long n,long long p,long long mod){
	if(p==0) return 1;
	if(p%2==0) return (modpow(n,p/2,mod)*modpow(n,p/2,mod))%mod;
	if(p%2==1) return (modpow(n,p-1,mod)*n)%mod;
	cerr<<"ERROR"<<endl;
	return 1;
}
