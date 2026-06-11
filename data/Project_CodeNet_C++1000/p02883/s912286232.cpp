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
	ll n,a[2*M],f[2*M];
	ll k,asum=0;
	cin>>n>>k;
	rep(i,0,n)cin>>a[i],asum+=a[i];
	rep(i,0,n)cin>>f[i];
	sort(a,a+n);sort(f,f+n,greater<>());

	if(asum<=k)print(0);
	else{
		ll l=-1,r=INF,mid=(l+r)/2;
		while(r>l+1){
			mid=(l+r)/2;
			ll atmp=0;
			rep(i,0,n)
				atmp+=max(a[i]-mid/f[i],(ll)0);
			if(atmp<=k)r=mid;
			else l=mid;
		}
		print(l+1);
	}
}