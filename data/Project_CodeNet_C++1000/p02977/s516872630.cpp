#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<cmath>
#include<iomanip>
#include<cstring>
#define initdp(a,b) for(int i=0;i<=a;i++)for(int j=0;j<=b;j++)dp[i][j]=-1;
#define fi first
#define se second
#define pb push_back
#define pii pair<int,int>
#define ll long long
#define pll pair<ll,ll>
#define rep(i,n) for(int i=0;i<n;i++)
#define repd(i,n) for(int i=n-1;i>=0;i--)
#define waste ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define inf 1e9+1
#define inf1 1e18+1
#define mod 1000000007
#define pie 3.14159265358979323846
#define N 1000005
#define mid(l,r) l+(r-l)/2
using namespace std;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int ddx[8]={1,1,0,-1,-1,-1,0,1},ddy[8]={0,1,1,1,0,-1,-1,-1};
void mad(ll &a,ll b){a=(a+b)%mod;if(a<0)a+=mod;}
ll gcd(ll a,ll b){ if(a>b)swap(a,b);if(!a)return b;return gcd(b%a,a);}
vector<pii>res;
void solve(){
	int n;
	cin>>n;
	if((n&-n)==n){cout<<"No";return;}
	cout<<"Yes\n";
	res.pb(pii(1,2));
	res.pb(pii(2,3));
	res.pb(pii(3,1+n));
	res.pb(pii(1+n,2+n));
	res.pb(pii(2+n,3+n));
	//int pre1=1,pre2=1;
	for(int i=4;i<n;i+=2){
		res.pb(pii(i,1));
		res.pb(pii(i+1,i));
		res.pb(pii(n+i+1,1));
		res.pb(pii(n+i,n+1+i));
		//pre1=i+1;
		//pre2=n+i;
	}
	if(n%2==0){
		res.pb(pii(n,n+n-1));
		int x=n^(n-1)^1;
		if(x&1)x+=n;
		res.pb(pii(n+n,x));
	}
	for(pii p:res)cout<<p.fi<<" "<<p.se<<"\n";
}
int main()
{
	waste;
	int t;
	//cin>>t;
	t=1;
	while(t--){
		solve();
	}
}