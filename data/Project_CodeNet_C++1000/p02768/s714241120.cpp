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
ll mod_pow(ll a,ll b){
	if(b==0)return 1;
	ll next=mod_pow(a,b/2);
	int num=1;
	if(b%2) num=a*(b%2)%mod;
	return num*(next*next%mod)%mod;
}
ll extGCD(ll a,ll b,ll &x,ll &y) {
    if(b==0){
       x=1;
       y=0;
       return a;
    }
    ll d=extGCD(b,a%b,y,x); // 再帰的に解く
    y-=a/b*x;
    return d;
}

ll mod_inv(ll a){//aの逆元
	ll x,y;
	extGCD(a,mod,x,y);
	return x%mod;
}

ll mod_conbination(ll a, ll b){//aCbの計算
    ll n=1,m=1;
	rep(i,b)n=n*(a-i)%mod;//分母
	rep(i,b)m=m*(i+1)%mod;//分子
	return n*mod_inv(m)%mod;
}
	
int main(){
	ll n,a,b;
	cin>>n>>a>>b;
	ll count=0;
	count=(mod_pow(2,n)-1-mod_conbination(n,a)-mod_conbination(n,b))%mod;
	if(count<0)count+=mod;
	cout<<count;
	return 0;
}