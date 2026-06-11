#include <bits/stdc++.h>
typedef long long ll;
#define  rep(i,a,b)for(long long i=a;i<b;++i)
#define  rrep(i,a,b)for(int i=a;i>=b;--i)
#define  yesno(flag)if(flag)cout<<"Yes"<<endl; else cout<<"No"<<endl;
using namespace std;
const ll INF=100000000000000LL;
const ll r197=1000000007;
typedef pair<ll,ll>P;
typedef pair<int,P>Pa;
bool Inframe(int a,int b,int c,int d,int h,int w){
	if(a+b>=0&&a+b<h&&c+d>=0&&c+d<w)return true;
	return false;
}
//void swap(ll a,ll b){
//	ll d;
//	d=a;
//	a=b;
//	b=d;
//	return;
//}
ll mypow(ll x,int m){
	if(m==0)return 1;
	if(m%2==0){
		int x2=mypow(x,m/2);
		return x2*x2;
	}else{
		int x2=mypow(x,m/2);
		return x2*x2*x;
	}
}
long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
//    	cout<<b<<endl;
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}
ll dp[301][301][301]={};
ll n,k;
ll h[303];
P hd[303];
int d[303];
ll reg(ll m,ll hi,ll l){
	if(dp[m][hi][l]!=-1)return dp[m][hi][l];
	if(m==n)return 0;
	ll res=INF,myhi=hd[hi].first;
	if(hi==0)myhi=0;
	res=min(res,reg(m+1,d[m+1],l)+max(0LL,h[m+1]-myhi));
	if(l<k){
		res=min(res,reg(m+1,hi,l+1));
	}
//	cout<<m<<" "<<myhi<<" "<<l<<" "<<res<<endl;
	return dp[m][hi][l]=res;

}

int main() {
	memset(dp,-1,sizeof(dp));
	cin>>n>>k;
	h[0]=0;
	hd[0]=P(1,0);
	rep(i,1,n+1){
		cin>>h[i];
		hd[i]=P(h[i],i);
	}
	sort(hd,hd+n+1);
	rep(i,0,n+1){
		d[hd[i].second]=i;
	}
	cout<<reg(0,0,0)<<endl;
	return 0;
}
