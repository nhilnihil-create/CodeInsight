#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<cstdio>
#define initdp(a,b) for(int i=0;i<=a;i++)for(int j=0;j<=b;j++)dp[i][j]=-1;
#define fi first
#define se second
#define pb push_back
#define pii pair<int,int>
#define ppi pair<pii,int>
#define pip pair<int,pii>
#define ll long long
#define pll pair<ll,ll>
#define rep(i,n) for(int i=0;i<n;i++)
#define repd(i,n) for(int i=n-1;i>=0;i--)
#define inf 1000000001
#define inf1 1000000000000000001
#define mod 1000000007
#define pie 3.14159265358979323846
#define N 1000005
#define mid(l,r) l+(r-l)/2
using namespace std;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int ddx[8]={1,1,0,-1,-1,-1,0,1},ddy[8]={0,1,1,1,0,-1,-1,-1};
void mad(ll &a,ll b){a=(a+b)%mod;if(a<0)a+=mod;}
ll gcd(ll a,ll b){ if(!a)return b;return gcd(b%a,a);}
int r[N],c[N];
int mk[N];
vector<int>ed[N];
void solve(){
	int h,w;
	cin>>h>>w;
	int m;
	cin>>m;
	map<int,map<int,int> >mp;
	int maxr=0,maxc=0;
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		mp[x][y]=1;
		r[x]++;
		c[y]++;
		maxr=max(maxr,r[x]);
		maxc=max(maxc,c[y]);
	}
	vector<int>rs;
	for(int i=1;i<=h;i++)if(r[i]==maxr)rs.pb(i);
	int ans=0;
	for(int i=1;i<=w;i++){
		if(c[i]==maxc)for(int j:rs){
			if(mp[j].find(i)==mp[j].end()){cout<<maxr+maxc<<"\n";return;}
		}
	}
	cout<<maxc+maxr-1<<"\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	//cin>>t;
	t=1;
	while(t--){
		solve();
	}
}