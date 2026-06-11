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

const int ss = 2e5+10;

ll n,k;
ll a[ss];

void input(){
	cin>>n>>k;
	rep(i,n){
		cin>>a[i];
		a[i]--;
	}
}

int solve(){
	ll num[ss]={};
	rep(i,ss)num[i]=-1;

	ll p=0, cnt=0;
	while(num[p]<0&&cnt<k){
		num[p]=cnt;
		cnt++;
		p=a[p];
	}

	if(cnt==k){
		return p+1;
	}

	k-=cnt;
	cnt=0;
	ll q=p;
	rep(i,ss)num[i]=-1;
	while(num[p]<0&&cnt<k){
		num[p]=cnt;
		cnt++;
		p=a[p];
	}
	if(cnt==k){
		return p+1;
	}

	// cout<<l<<" "<<cnt<<" "<<p<<" "<<num[p]<<endl;

	// k-=num[p];
	k%=cnt;
	p=q;
	while(k>0){
		p=a[p];
		k--;
	}
	return p+1;
}

int main()
{
	input();
	cout<<solve()<<endl;
	return 0;
}