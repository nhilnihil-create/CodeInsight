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
const double eps=1e-9;
const ll mod=1e9+7;
const int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};

int n;
vi a,b;

int main(){
	cin>>n;
	a=vi(n);
	b=vi(n+1);
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		a[x-1]++;
	}
	sort(a.begin(),a.end());
	int id=0,s=0;
	for(int i=1;i<=n;i++){
		while(id<n&&a[id]<i) s+=a[id++];
		b[s/i+(n-id)]=i;
	}
	for(int i=n-1;i>=0;i--) b[i]=max(b[i],b[i+1]);
	for(int i=1;i<=n;i++) cout<<b[i]<<endl;
}