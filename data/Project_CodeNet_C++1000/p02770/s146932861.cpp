#include <bits/stdc++.h>
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
typedef pair<int,P> pip;
typedef vector<pip> vip;
const int inf=1<<30;
const ll INF=1ll<<60;
const double pi=acos(-1);
const double eps=1e-8;
const ll mod=998244353;
const int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};

ll n,q;
vl a;

int main(){
	cin>>n>>q;
	a=vl(n);
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<q;i++){
		ll N,x,m;
		cin>>N>>x>>m;
		ll sum=x%m,res=N-1;
		for(int j=0;j<n;j++){
			ll num=(N-1)/n+(j<(N-1)%n?1:0);
//			cout<<num<<endl;
			if(a[j]%m==0) res-=num;
			else sum+=a[j]%m*num;
		}
		res-=sum/m;
		cout<<res<<endl;
	}
}