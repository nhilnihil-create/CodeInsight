#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<n;i++)
#define all(v) v.begin(),v.end()
#define P pair<int,int>
#define len(s) (int)s.size()
#define pb push_back

template<class T> inline bool chmin(T &a, T b){
	if(a>b){a=b;return true;}
	return false;
}
template<class T> inline bool chmax(T &a, T b){
	if(a<b){a=b;return true;}
	return false;
}
constexpr int mod = 1e9+7;
constexpr int inf = 3e18;

int N;
P A[2005];
int dp[2005][2005];
signed main(){
	cin>>N;
	rep(i,N){
		cin>>A[i].first;A[i].second=i;
	}
	sort(A,A+N,greater<>());
	rep(i,N+1)rep(j,N+1)dp[i][j]=-inf;
	dp[0][0]=0;
	rep(i,N){
		rep(j,i+1){
			if(dp[i][j]==-inf)continue;
			chmax(dp[i+1][j+1],dp[i][j]+A[i].first*abs(j-A[i].second));
			chmax(dp[i+1][j],dp[i][j]+A[i].first*abs(N-1-(i-j)-A[i].second));
		}
	}
	int ans=-inf;
	rep(i,N+1)chmax(ans,dp[N][i]);
	cout<<ans<<endl;
}
