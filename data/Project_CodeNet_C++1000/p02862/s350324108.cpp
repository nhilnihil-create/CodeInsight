#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define rep(i,n) for(int i=0;i<(n);i++)
#define init(a,i) for(int k=0;k<(i);k++)(a)[k]=0
#define in(a,i) for(int k=0;k<(i);k++)cin>>(a)[k]
#define all(a)  (a).begin(),(a).end()
#define el(a) (a).end()-(a).begin()
#define mod 1000000007
#define inf 2147483647
ll extGCD(ll a,ll b,ll &x,ll &y) {
    if(b==0){
       x=1;
       y=0;
       return a;
    }
    ll d=extGCD(b,a%b,y,x);
    y-=a/b*x;
    return d;
}

ll mod_inv(ll a){//aの逆元
	ll x,y;
	extGCD(a,mod,x,y);
	return x%mod;
}

ll conbination(ll n,ll k){
	ll a=1,b=1;
	rep(i,k){
		a=a*(n-i)%mod;
		b=b*(i+1)%mod;
	}
	return a*mod_inv(b)%mod;
}	
int main(){
	ll X,Y;
	cin>>X>>Y;
	if((X+Y)%3||X>2*Y||Y>2*X){
		cout<<0;
		return 0;
	}
	ll times=(X+Y)/3;
	X-=times;
	Y-=times;
	ll ans=conbination(times,X);
	if(ans<0)ans+=mod;
	cout<<ans;
	return 0;
}