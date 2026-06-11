#include <bits/stdc++.h>
#define syosu(x) fixed<<setprecision(x)
using namespace std;
typedef long long ll;
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

ll n,t=0,res=0;
vl a,b;

bool f(int i){
	int L=b[(i+n-1)%n],R=b[(i+1)%n];
	return L<b[i]&&b[i]>R&&L+R<=b[i]&&b[i]>=a[i];
}

int main(){
	cin>>n;
	a=b=vl(n);
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++){
		cin>>b[i];
		if(a[i]==b[i]) t++;
	}
	queue<int> q;
	for(int i=0;i<n;i++) if(f(i)) q.push(i);
	while(!q.empty()){
		ll i=q.front();q.pop();
		if(!f(i)) continue;
		ll L=b[(i+n-1)%n],R=b[(i+1)%n],s=L+R,tmp=min((b[i]-a[i])/s,(b[i]-max(L,R)-1)/s+1);
		res+=tmp;
		b[i]-=tmp*s;
		if(b[i]==a[i]) t++;
		if(f((i+n-1)%n)) q.push((i+n-1)%n);
		if(f((i+1)%n)) q.push((i+1)%n);
	}
	if(t<n) res=-1;
	cout<<res<<endl;
}