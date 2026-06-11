#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vl=vector<ll>;
#define MOD 1000000007
ll mod_pow(ll x, ll p){
	ll res=1;
	ll n=x;
	while(p>0){
		if(p&1==1)res=(res*n)%13;
		n=(n*n)%13;
		p=(p>>1);
	}
	return res;
}
int ctoi(char c){
    return (int)c-(int)'0';
}
int main() {
    string S; cin>>S;
    int N=S.size();
    vector<vl> dp(N+1,vl(13,0));
    if(S[0]=='?'){
        for (int i = 0; i < 10; i++){
            int rem=(i*mod_pow(10,N-1))%13;
            dp[0][rem]++;
        }
    }else{
        dp[0][ctoi(S[0])]=1;
    }
    for (int i = 1; i <= N; i++){
        if(S[i-1]=='?'){
            for (int j = 0; j < 10; j++){
                int rem=(j*mod_pow(10,N-i))%13;
                if(i==1){
                    dp[1][rem]++;
                }else{
                    for (int k = 0; k < 13; k++){
                        dp[i][(k+rem)%13]+=dp[i-1][k];
                        dp[i][(k+rem)%13]%=MOD;
                    }
                }
            }
        }else{
            int rem=(ctoi(S[i-1])*mod_pow(10,N-i))%13;
            if(i==1){
                dp[1][rem]=1;
            }else{
                for (int k = 0; k < 13; k++){
                    dp[i][(k+rem)%13]+=dp[i-1][k];
                    dp[i][(k+rem)%13]%=MOD;
                }
            }
        }
    }
    cout<<dp[N][5]<<endl;
}