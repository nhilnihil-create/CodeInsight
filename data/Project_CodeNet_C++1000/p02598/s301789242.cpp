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
typedef pair<P,int> pip;
typedef vector<pip> vip;
const int inf=1<<30;
const ll INF=1ll<<60;
const double pi=acos(-1);
const double eps=1e-8;
const ll mod=1e9+7;
const int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};

int n,k;
vi a;

bool f(int x){
	ll t=0;
	for(int i=0;i<n;i++) t+=(a[i]-1)/x;
	return t<=k;
}

int main(){
	cin>>n>>k;
	a=vi(n);
	for(int i=0;i<n;i++) cin>>a[i];
	int l=0,r=inf;
	while(r-l>1){
		int m=(l+r)/2;
		if(f(m)) r=m;
		else l=m;
	}
	cout<<r<<endl;
}