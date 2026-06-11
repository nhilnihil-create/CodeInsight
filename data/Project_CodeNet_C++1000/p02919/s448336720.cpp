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
#define N 100005
#define mid(l,r) l+(r-l)/2
using namespace std;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int ddx[8]={1,1,0,-1,-1,-1,0,1},ddy[8]={0,1,1,1,0,-1,-1,-1};
void mad(ll &a,ll b){a=(a+b)%mod;if(a<0)a+=mod;}
ll gcd(ll a,ll b){ if(!a)return b;return gcd(b%a,a);}
pii st[4*N+1][2];
pii l[N],r[N];
int n;
pii merge(pii a,pii b,int c){
	vector<int>v;
	v.pb(a.fi);v.pb(a.se);
	v.pb(b.fi);v.pb(b.se);
	sort(v.begin(), v.end());
	if(c)return pii(v[0],v[1]);
	else return pii(v[3],v[2]);
}
void update(int i,int l,int r,int x,int v,int c){
	if(l==r){
		st[i][c].fi=v;
		if(c)st[i][c].se=n+1;
		else st[i][c].se=0;
		return;
	}
	if(mid(l,r)>=x)update(2*i+1,l,mid(l,r),x,v,c);
	else update(2*i+2,mid(l,r)+1,r,x,v,c);
	//if(c)st[i][c]=min(st[2*i+1][c],st[2*i+2][c]);
	//else st[i][c]=max(st[2*i+1][c],st[2*i+2][c]);
	st[i][c]=merge(st[2*i+1][c],st[2*i+2][c],c);
}
pii qry(int i,int l,int r,int l1,int r1,int c){
	if(r<l1||r1<l){
		if(c)return pii(n+1,n+1);
		else return pii(0,0);
	}
	if(l1<=l&&r<=r1)return st[i][c];
	pii q1=qry(2*i+1,l,mid(l,r),l1,r1,c);
	pii q2=qry(2*i+2,mid(l,r)+1,r,l1,r1,c);
	//cout<<q1<<" "<<q2<<" "<<l<<" "<<r<<"\n";
	return merge(q1,q2,c);
}
void solve(){
	cin>>n;
	ll int a[n+2];
	rep(i,n){
		cin>>a[i+1];
	}
	for(int i=n+1;i;i--)update(0,0,n+1,i,n+1,1);
	for(int i=n;i;i--){
		r[i]=qry(0,0,n+1,a[i]+1,n+1,1);
		update(0,0,n+1,a[i],i,1);
		//cout<<r[i]<<" "<<i<<"\n";
	}
	for(int i=1;i<=n;i++){
		l[i]=qry(0,0,n+1,a[i]+1,n+1,0);
		update(0,0,n+1,a[i],i,0);
		//cout<<l[i]<<" "<<i<<"\n";
	}
	r[n+1]=pii(n+1,n+1);
	l[0]=pii(0,0);
	ll ans=0;
	for(ll int i=1;i<=n;i++){
		ll int l1=l[i].fi;
		ll int ll1=l[i].se;
		ll int r1=r[i].fi;
		ll int rr1=r[i].se;
		ll cnt=(l1-ll1)*(r1-i)+(i-l1)*(rr1-r1);
		ans+=cnt*a[i];
		//cout<<cnt<<" "<<ll1<<" "<<l1<<" "<<i<<" "<<r1<<" "<<rr1<<"\n";
	}
	cout<<ans;
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