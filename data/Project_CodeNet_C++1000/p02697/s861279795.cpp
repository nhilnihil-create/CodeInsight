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
	int n,m;
	cin>>n>>m;
	
	int round=m;
	int cnt=0;
	m=2*m+1;

	vector<P> ans;
	int l=1,r=m/2;
	if(round%2==0)r++;
	while(cnt<round){
		if(l==r) break;
		ans.push_back(make_pair(l,r));
		l++;r--;
		cnt++;
	}
	l=m/2+1,r=m;
	if(round%2==0)l++;
	while(cnt<round){
		if(l==r)break;
		ans.push_back(make_pair(l,r));
		l++;r--;
		cnt++;
	}
	for(auto x:ans)cout<<x.first<<" "<<x.second<<endl;
	return 0;
}