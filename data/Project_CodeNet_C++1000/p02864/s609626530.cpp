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

int N,K,H[305];
vector<int>x={0};
int dp[305][305][305];
signed main(){
	cin>>N>>K;
	rep(i,N){
		cin>>H[i];x.pb(H[i]);
	}
	sort(all(x));x.erase(unique(all(x)),x.end());
	int M=len(x);
	rep(i,N+1)rep(j,K+1)rep(k,M)dp[i][j][k]=inf;
	dp[0][0][0]=0;
	rep(i,N){
		H[i]=lower_bound(all(x),H[i])-x.begin();
		int memo1[305][305],memo2[305][305];
		rep(j,i+2)rep(k,M)memo1[j][k]=memo2[j][k]=inf;
		rep(j,i+1){
			rep(k,M){
				chmin(dp[i+1][j][H[i]],dp[i][j][k]+max(0ll,x[H[i]]-x[k]));
				chmin(memo1[j+1][k],dp[i][j][k]);
				chmin(memo2[j+1][k],dp[i][j][k]);
			}
		}
		rep(j,i+2)for(int k=M-1;k>0;k--){
			chmin(memo1[j][k-1],memo1[j][k]);
		}
		rep(j,i+2)rep(k,M-1){
			chmin(memo2[j][k+1],memo2[j][k]+x[k+1]-x[k]);
		}
		rep(j,i+2)rep(k,M){
			chmin(dp[i+1][j][k],min(memo1[j][k],memo2[j][k]));
		}
	}
	int ans=inf;
	rep(i,M)chmin(ans,dp[N][K][i]);
	cout<<ans<<endl;
}
