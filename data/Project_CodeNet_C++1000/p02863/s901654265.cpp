#include "bits/stdc++.h"
using namespace std;
using ll=long long;
#define rep(i,a,n) for(int i=a;i<n;i++)
#define ALL(s) s.begin(),s.end()
#define P pair<ll,ll>
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define print(n) cout<<n<<endl
const int M=100111;
const int mod=1000000007;
const int inf=1000000007;
const long long INF=1000000000000000007;
int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};
int ddx[8]={1,-1,0,0,1,-1,-1,1},ddy[8]={0,0,1,-1,1,-1,1,-1};

const int maxn=303;

int n,m,l,a,b,c;
ll d[maxn][maxn],tt[maxn][maxn];
void floyd(ll dp[303][303]){rep(k,1,n+1)rep(i,1,n+1)rep(j,1,n+1)dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);}

int main(){
	int n,t;
	int dp[M];
	fill(dp,dp+M,0);
	pair<int,int> p[M];
	cin>>n>>t;
	rep(i,0,n)cin>>p[i].first>>p[i].second;
	sort(p,p+n);

	rep(i,0,n){
		int a,b;
		a=p[i].first,b=p[i].second;
		for(int j=t-1;j>=0;j--)
			dp[j+a]=max(dp[j+a],dp[j]+b);
	}
	int ans=0;
	rep(i,0,6001)ans=max(ans,dp[i]);
	print(ans);
}