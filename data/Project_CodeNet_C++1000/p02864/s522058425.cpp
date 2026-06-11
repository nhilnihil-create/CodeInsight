#include <bits/stdc++.h>
#define syosu(x) fixed<<setprecision(x)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
typedef pair<double,double> pdd;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<string> vs;
typedef vector<P> vp;
typedef vector<vp> vvp;
typedef vector<pll> vpll;
typedef pair<int,P> pip;
typedef vector<pip> vip;
const int inf=1<<30;
const ll INF=1ll<<55;
const double pi=acos(-1);
const double eps=1e-8;
const ll mod=1e9+7;
const int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};

int n,k;
vi a;

int main(){
	cin>>n>>k;
	a=vi(n+2);
	for(int i=1;i<=n;i++) cin>>a[i];
	vvl dp(n+2,vl(k+1,INF));
	dp[0][0]=0;
	for(int i=0;i<=n;i++) for(int j=0;j<=k;j++) if(dp[i][j]<INF){
		for(int I=i+1;I<=n+1;I++){
			int J=I-i-1+j;
			if(J<=k){
				dp[I][J]=min(dp[I][J],dp[i][j]+max(0,a[I]-a[i]));
			}
		}
	}
	ll res=INF;
	for(int i=0;i<=k;i++) res=min(res,dp[n+1][i]);
	cout<<res<<endl;
}