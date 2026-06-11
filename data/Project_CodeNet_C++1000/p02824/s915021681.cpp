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
const ll mod=1e9+7;
const int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};

ll N,M,V,K;
vl a;

bool f(int I){
	if(N-I-K<1) return 1;
	vl b;
	for(int i=1;i<=N-I-K;i++) b.push_back(a[I+i]);
	ll x=a[I]+M,t=max(0LL,V-I-K);
	ll n=b.size(),sum=0;
	for(int i=0;i<n;i++) if(x<b[i]) return 0;
	for(int i=0;i<n;i++) sum+=min(M,x-b[i]);
	return sum/M>=t;
}

int main(){
	cin>>N>>M>>V>>K;
	a=vl(N);
	for(auto &i:a) cin>>i;
	sort(a.begin(),a.end());
	int l=-1,r=N-1;
	while(r-l>1){
		int m=(l+r)/2;
		if(f(m)) r=m;
		else l=m;
	}
	cout<<N-r<<endl;
}