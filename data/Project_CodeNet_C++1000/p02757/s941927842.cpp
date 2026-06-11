#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(int)(n); i++)

using namespace std;
using LL = long long;
using P = pair<int,int>;
LL mod;

LL modpow(LL x, LL n){
	LL r=1;
	while(n){
		if(n&1) r=r*x%mod;
		x=x*x%mod;
		n>>=1;
	}
	return r;
}

int main(){
	LL N, P;
	cin >> N >> P;
	string S;
	cin >> S;
	LL ans=0;
	if(P==2 || P==5){
		for(LL i=0; i<N; i++){
			LL n=S[i]-'0';
			if(n%P==0) ans+=i+1;
		}
		cout << ans << endl;
		return 0;
	}
	reverse(S.begin(),S.end());
	mod=P;
	vector<LL> dp(N+1);
	map<LL,LL> m;
	m[0]++;
	rep(i,N){
		LL n=S[i]-'0';
		dp[i+1]=(dp[i]+n*modpow(10,i))%mod;
		dp[i+1]%=mod;
		m[dp[i+1]]++;
	}
	for(auto itr:m) ans+=itr.second*(itr.second-1)/2;
	cout << ans << endl;

	return 0;
}