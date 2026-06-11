#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#define syosu(x) fixed<<setprecision(x)
using namespace std;
typedef long long ll;
typedef unsigned int uint;
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
typedef pair<P,int> pip;
typedef vector<pip> vip;
const int inf=1<<30;
const ll INF=1ll<<60;
const double pi=acos(-1);
const double eps=1e-8;
const ll mod=1e9+7;
const int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};

ll n,res=0;
vvi g;

void dfs(int v,int p=-1){
	ll l=v+1,r=n-v;
	if(p>=0&&p<v) l=v-p;
	if(p>v) r=p-v;
	res+=l*r;
	for(auto u:g[v]) if(u!=p) dfs(u,v);
}

int main(){
	cin>>n;
	g=vvi(n);
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		u--,v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(0);
	cout<<res<<endl;
}