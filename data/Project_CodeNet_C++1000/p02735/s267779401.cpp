#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
#define rep2(i,a,n) for(int i=a;i<n;i++)
#define been(ix) (ix).begin(),(ix).end()
using namespace std;
typedef long long ll; 
typedef vector<int> vi;
typedef vector<long long> vl;
const ll INFL = 1e18;
const int INF = 1001001001; 
typedef pair<int,int> P;
#define foreach(ix,i) for(auto& (ix) : (i))
typedef long double ld;
const int mod =1000000007;
const double PI = acos(-1);

int main(){
	int h,w;cin>>h>>w;
	char ma[h][w];
	rep(i,h)rep(j,w)cin>>ma[i][j];
	int dp[h][w];
	rep(i,h)rep(j,w)dp[i][j]=INF;
	if(ma[0][0]=='#')dp[0][0]=1;
	else dp[0][0]=0;
	rep(i,h)rep(j,w){
		if(i!=h-1){
			dp[i+1][j]=min(dp[i+1][j],dp[i][j]+(ma[i+1][j]=='#'&&ma[i][j]=='.'? 1:0));
		}
		if(j!=w-1){
			dp[i][j+1]=min(dp[i][j+1],dp[i][j]+(ma[i][j+1]=='#'&&ma[i][j]=='.'? 1:0));
		}
	}
	cout<<dp[h-1][w-1]<<endl;
}