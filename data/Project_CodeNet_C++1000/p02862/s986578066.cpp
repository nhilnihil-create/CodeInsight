#include <bits/stdc++.h>
#define rep(i,n1) for(int i=0;i<n1;++i)
#define rrep(i,n) for(int i=n-1;i>=0;--i)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define yesno(flg) if(flg){cout<<'YES'<<endl;}else{cout<<'NO'<<endl;}
#define vi vector<int>
#define pb push_back
#define i197 1000000007
#define MAX_N 200002
#define PI 3.141592653589793
using namespace std;

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<Pii,int> Piii;
typedef pair<int,ll> Pil;
typedef pair<ll,ll> Pll;
typedef pair<string,int> Psi;
typedef pair<Psi,int> Psii;

const ll inf=1000000007;
struct edge{
	int myc,to,c,cost;
};
struct pos{
	int to,cost,color;
};
int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0};

vi vec[200001];
int x[200001]={};
int dp[200001];

ll modpow(ll a){
	ll res=1;
	int n=inf-2;
	while(n>0){
		if(n&1)res = res * a % inf;
		a=a*a % inf;
		n>>=1;
	}
	return res;
}
int main() {
	ll x,y;
	cin>>x>>y;
	if((x+y)%3>0||(2*y-x)<0||(2*y-x)%3>0||(2*x-y)<0||(2*x-y)%3>0){
		printf("0");
		return 0;
	}
	ll r=1;
	for(ll i=2;i<=(x+y)/3;++i){
		r*=i;
		r%=inf;
	}
	for(ll i=2;i<=(2*x-y)/3;++i){
		r*=modpow(i);
		r%=inf;
	}
	for(ll i=2;i<=(2*y-x)/3;++i){
		r*=modpow(i);
		r%=inf;
	}
	cout<<r;
	return 0;
}
