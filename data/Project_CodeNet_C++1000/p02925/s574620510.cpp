#include<bits/stdc++.h>
#define fo(i,a,b) for((i)=(a);i<=(b);i++)
#define rfo(i,a,b) for((i)=(a);i>=(b);i--)
#define inrange(x,y,z) (((x)>=(y))&&((x)<=(z)))
#define ALL(vec) ((vec).begin(),(vec).end())
#define SOR(vec) sort(ALL(vec))
#define UNI(vec) (vec).erase(unique(ALL(vec)),(vec).end())
using namespace std;
int n;
int a[1030][1030];
int encode(int x,int y){
	if(x>y) swap(x,y);
	return (n*2LL-x)*(x-1LL)/2LL+(y-x);
}
int dp[1000100];
vector<int> ga[1000100];
int vis[1000100];
int path(int x){
	if(vis[x]==1){
		cout<<"-1"<<endl;
		exit(0);
	}
	if(dp[x]!=-1)
		return dp[x];
	dp[x]=0;
	vis[x]=1;
	for(int y:ga[x])
		dp[x]=max(dp[x],path(y));
	dp[x]++;
	vis[x]=2;
	return dp[x];
}
int main(){
	#ifdef FILIN
		#ifndef LOCAL
			freopen(FILIN,"r",stdin);
			freopen(FILOUT,"w",stdout);
		#endif
	#endif
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-1;j++){
			cin>>a[i][j];
		}
		for(int j=1;j<=n-2;j++){
			ga[encode(i,a[i][j])].push_back(encode(i,a[i][j+1]));
		}
	}
	int res=0;
	memset(dp,-1,sizeof(dp));
	for(int i=1;i<=n*(n-1)/2;i++){
		res=max(res,path(i));
	}
	cout<<res<<endl;
	return 0;
}
