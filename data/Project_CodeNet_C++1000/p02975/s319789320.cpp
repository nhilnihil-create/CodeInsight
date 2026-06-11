#include <bits/stdc++.h>
#include <math.h>

using namespace std;

long long inf=1000000007;

long long modpow(long long n,long long p,long long mod);

int main(){
	long long n;
	cin>>n;
	set<long long> s;
	map<long long,long long> m;

	for(long long i=0;i<n;i++){
		long long hoge;
		cin>>hoge;
		m[hoge]++;
		s.insert(hoge);
	}

	string ans="No";

	if(s.size()==1 && m.count(0)){
		ans="Yes";
	}else if(n%3==0){
		if(s.size()==2 && m[0]*2==m[*next(s.begin())]) ans="Yes";
		if(s.size()==3){
			long long x=*s.begin();
			x^=*next(s.begin());
			x^=*next(s.begin(),2);
			if(x==0 && m[*s.begin()]==m[*next(s.begin())] && m[*next(s.begin())]==m[*next(s.begin(),2)]) ans="Yes";
		}
	}

	cout<<ans<<endl;

	return 0;
}

long long modpow(long long n,long long p,long long mod){
	if(p==0) return 1;
	if(p%2==0) return (modpow(n,p/2,mod)*modpow(n,p/2,mod))%mod;
	if(p%2==1) return (modpow(n,p-1,mod)*n)%mod;
	cerr<<"ERROR"<<endl;
	return 1;
}
