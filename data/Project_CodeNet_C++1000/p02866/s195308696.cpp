#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int,int> P;

#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<(b);i++)
#define repr(i,b,a) for(int i=int(b);i>=(a);i--)
#define all(x) x.begin(),x.end()

const ll mod = 998244353;
const ll INF = 1e9;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
bool valid(int lx,int ux,int ly,int uy,int x,int y){
	return lx<=x&&x<ux&&ly<=y&&y<uy; 
}
ll power(ll x,ll p){
	if(p==0)return 1;
	ll res=power(x*x%mod,p/2);
	if(p%2==1)res=res*x%mod;
	return res;
}

int main()
{
	ll n;
	cin>>n;
	vector<ll> dist(n);
	rep(i,n)cin>>dist[i];
	if(dist[0]>0){
		cout<<0<<endl;
		return 0;
	}

	vector<ll> cnt(n,0);
	rep(i,n){
		cnt[dist[i]]++;
	}
	if(cnt[0]>1){
		cout<<0<<endl;
		return 0;
	}
	ll ans = 1;
	ll max_ = *max_element(all(dist));
	rep(i,max_+1){
		if(i==0)ans *= cnt[i];
		else ans *= power(cnt[i-1],cnt[i]);
		ans %= mod;
	}
	cout<<ans<<endl;
	 
	return 0;
}