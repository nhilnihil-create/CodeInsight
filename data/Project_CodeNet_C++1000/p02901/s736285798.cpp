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
	int b,c; int A[M],C[M] = {};
	rep(i,0,M){
		cin>>A[i]>>b;
		rep(j,0,b){ cin>>c; C[i] |= (1<<c-1); }
	}
	int dp[1<<N]; dp[0] = 0;
	rep(i,1,1<<N) dp[i] = inf;
	rep(i,0,1<<N)rep(j,0,M){
		dp[i|C[j]] = min(dp[i|C[j]], dp[i] + A[j]);
	}
    if(dp[(1<<N)-1] == inf) cout<<-1<<endl;
    else cout<<dp[(1<<N)-1]<<endl;
}