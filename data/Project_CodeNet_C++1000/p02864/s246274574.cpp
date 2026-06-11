#include <bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i,n) for(int i = 0;i < (int)(n);i++)
#define RREP(i,n) for(int i = (int)n-1;i >= 0;i--)
#define FOR(i,s,n) for(int i = s;i < (int)n;i++)
#define RFOR(i,s,n) for(int i = (int)n-1;i >= s;i--)
#define ALL(a) a.begin(),a.end()
#define IN(a, x, b) (a<=x && x<b)
template<class T>inline bool CHMAX(T&a,T b){if(a<b){a = b;return true;}return false;}
template<class T>inline bool CHMIN(T&a,T b){if(a>b){a = b;return true;}return false;}
constexpr long long INF = 1e18;

int dp[303][303][303];
map<int,int>mp;

signed main(){
	int N,K;
	cin>>N>>K;
	vector<int>a(N);
	int cnt = 0;
	REP(i,N){
		cin>>a[i];
		if(!mp.count(a[i]))mp[a[i]]=cnt++;
	}
	REP(i,303)REP(j,303)REP(k,303)dp[i][j][k]=INF;
	mp[0]=cnt++;
	vector<int>mpInv(cnt);
	for(auto e:mp){
		mpInv[e.second]=e.first;
	}
	dp[0][0][mp[0]]=0;
	REP(i,N){
		REP(j,K+1){
			REP(k,cnt){
				if(dp[i][j][k]==INF)continue;
				CHMIN(dp[i+1][j+1][k],dp[i][j][k]);
				CHMIN(dp[i+1][j][mp[a[i]]],dp[i][j][k]+max(0ll,a[i]-mpInv[k]));
			}
		}
	}
	int ans = INF;
	REP(i,cnt)CHMIN(ans,dp[N][K][i]);
	cout<<ans<<endl;
}