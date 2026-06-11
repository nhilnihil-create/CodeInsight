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

void solve(){
	int n;
	cin>>n;
	int l[n];
	rep(i,n)cin>>l[i];
	sort(l,l+n);
	ll ans=0;
	//for(int i=0;i<n;i++)cout<<l[i]<<" ";cout<<"\n";
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			int x=lower_bound(l,l+n,l[i]+l[j])-l;
			int y=upper_bound(l,l+n,l[j]-l[i])-l;
			if(l[i]<l[i]+l[j])x--;
			if(l[i]<=l[j]-l[i])y--;
			if(l[j]<l[i]+l[j])x--;
			if(l[j]<=l[j]-l[i])y--;
			//x=max(0,x);
			//y=max()
			//cout<<x<<" "<<y<<" "<<l[i]+l[j]<<" "<<l[j]-l[i]<<"\n";
			ans+=(ll)(x-y);
		}
	}
	cout<<ans/3ll;
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