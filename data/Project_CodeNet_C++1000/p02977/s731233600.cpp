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
typedef pair<ll,pll> pip;
typedef vector<pip> vip;
const int inf=1<<30;
const ll INF=1ll<<60;
const double pi=acos(-1);
const double eps=1e-9;
const ll mod=998244353;
const int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};

int n;
vi a,b;

void add(int u,int v){
	a.push_back(u);
	b.push_back(v);
}

int main(){
	cin>>n;
	int t=0;
	for(int i=0;i<20;i++) t+=(n>>i)%2;
	if(t==1){
		cout<<"No"<<endl;
		return 0;
	}
	cout<<"Yes"<<endl;
	add(2,1);
	add(1,3);
	add(3,n+2);
	add(n+2,n+1);
	add(n+1,n+3);
	for(int i=4;i<n;i+=2){
		add(i,1);
		add(i+1,i);
		add(n+i+1,n+1);
		add(n+i,n+i+1);
	}
	if(n%2==0){
		t=1;
		while(2*t<=n) t*=2;
		add(n-t,n);
		add(2*n,n+t+1);
	}
	for(int i=0;i<2*n-1;i++) cout<<a[i]<<' '<<b[i]<<endl;
}