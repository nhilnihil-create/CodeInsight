#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define print(A,x,n) rep(i,0,n){cout<<(i ? " ":"")<<A[i]x;}cout<<endl;
#define pprint(A,y,m,n) rep(j,0,m){print(A[j],y,n);}
const long mod=1e9+7;
const int size=1e5;
const int inf=1e9;
int main(){
	int N,M;cin>>N>>M;
	int s[N],t[M];
	rep(i,0,N) cin>>s[i];
	rep(i,0,M) cin>>t[i];
	long dp[N+1][M+1] = {};
	rep(i,1,N+1)rep(j,1,M+1){
		if(s[i-1] == t[j-1]) dp[i][j] = (dp[i-1][j] + dp[i][j-1] + 1) % mod;
        else dp[i][j] = (dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + mod) % mod;
	}cout<<(dp[N][M] + 1) % mod<<endl;//pprint(dp,,N+1,M+1);
}