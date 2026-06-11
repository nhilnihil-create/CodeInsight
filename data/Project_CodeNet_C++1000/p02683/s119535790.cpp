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

int n,m,x;
int a[15][15], c[15];

void input(){
	cin>>n>>m>>x;
	rep(i,n){
		cin>>c[i];
		rep(j,m)cin>>a[i][j];
	}
}

int solve(){
	int ret=INF;
	rep(bit, (1<<n)){
		int buy[15]={};
		int tmp=0;
		rep(i,n){
			if(bit & (1<<i)){
				rep(j,m)buy[j]+=a[i][j];
				tmp+=c[i];
			}
		}
		rep(j,m){
			if(buy[j]<x) tmp = INF;
		}
		ret = min(ret, tmp);
	}
	return ret;
}

int main()
{
	input();
	int ans=solve();
	cout<<(ans<INF?ans:-1)<<endl;
	return 0;
}