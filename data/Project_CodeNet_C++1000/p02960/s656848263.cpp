#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(int)(n); i++)

using namespace std;
typedef long long LL;
const int mod=13;
const LL MOD=1e9+7;

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
	string S;
	cin >> S;
	LL dp[100010][13]={0};
	dp[0][0]=1;
	int N=S.size();
	rep(i,N){
		rep(j,13){
			if(S[N-1-i]=='?'){
				rep(k,10){
					int n=modpow(10,i)*k;
					dp[i+1][(j+n)%mod]+=dp[i][j];
                  	dp[i+1][(j+n)%mod]%=MOD;
				}
			}
			else{
				int k=S[N-1-i]-'0';
				int n=modpow(10,i)*k;
				dp[i+1][(j+n)%mod]+=dp[i][j];
              	dp[i+1][(j+n)%mod]%=MOD;
			}
		}
	}
	cout << dp[N][5] << endl;

	return 0;
}