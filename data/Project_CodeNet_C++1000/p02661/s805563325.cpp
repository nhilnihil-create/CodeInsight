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

int main()
{
	int n;
	cin>>n;
	vector<int> a(n), b(n);
	rep(i,n)cin>>a[i]>>b[i];
	sort(all(a));
	sort(all(b));
	int med_a, med_b;
	if(n%2==0){
		n--;
		med_a=(a[n/2]+a[n/2+1]);
		med_b=(b[n/2]+b[n/2+1]);
	}else{
		n--;
		med_a=a[n/2];
		med_b=b[n/2];
	}


	cout<<med_b-med_a+1<<endl;

	return 0;
}