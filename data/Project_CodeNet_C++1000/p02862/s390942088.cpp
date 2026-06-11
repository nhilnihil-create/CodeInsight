#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
ll power(ll a,ll b){return b?power(a*a%mod,b/2)*(b%2?a:1)%mod:1;}
ll C(ll n,ll k)
{
	ll x=1,y=1;
	for(ll i=1;i<=k;i++)
	{
		x=x*(n-i+1)%mod;
		y=y*i%mod;
	}
	return x*power(y,mod-2)%mod;
}

int main(){
    ll x,y;
    cin>>x>>y;
    if((x+y)%3!=0){
        printf("0");
        exit(0);
    }
    //cout<<(x+y)/3<<" "<<(2*x-y)/3<<" "<<(2*y-x)/3<<endl;
    if(2*x-y>=0){
        printf("%lld\n",C((x+y)/3,(2*x-y)/3));
    }else if(2*y-x>=0){
        printf("%lld\n",C((x+y)/3,(2*y-x)/3));
    }
}
