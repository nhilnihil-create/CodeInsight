#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int,int> P;

#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<(b);i++)
#define repr(i,b,a) for(int i=int(b);i>=(a);i--)
#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
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
	int x,y,a,b,c;
	cin>>x>>y>>a>>b>>c;
	vector<ll> p(a),q(b),r(c);
	rep(i,a)cin>>p[i];
	rep(i,b)cin>>q[i];
	rep(i,c)cin>>r[i];

	sort(all(p));
	reverse(all(p));
	sort(all(q));
	reverse(all(q));

	vector<ll> tmp;
	rep(i,x) tmp.push_back(p[i]);
	rep(i,y)tmp.push_back(q[i]);
	rep(i,c)tmp.push_back(r[i]);

	sort(all(tmp));
	reverse(all(tmp));
	ll ans=0;
	rep(i,x+y)ans+=tmp[i];

	cout<<ans<<endl;

	return 0;
}