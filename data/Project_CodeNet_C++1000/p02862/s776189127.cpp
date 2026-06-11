#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<long long,long long>
#define ii pair<int,int>
#define mod 1000000007
#define endl '\n'
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);

ll power(ll a,ll b){
	ll ans=1;
	while(b>0){
		if(b%2!=0){
			ans=(ans*a)%mod;
		}
		a=((a%mod)*(a%mod))%mod;
		b>>=1;
	}
	return ans;
}

void sieve(int n){
	bool prime[n+1];
	memset(prime,true,sizeof(prime));
	for(int p=2;p*p<=n;p++){
		if(prime[p]){
			for(int i=p*p;i<=n;i+=p)
				prime[i]=false;
		}
	}
	for(int p=2;p<=n;p++){
		if(prime[p])
			cout<<p<<" ";
	}
}

ll fact[2000005],modi[2000005];
void pre(){
    fact[0]=1;
    modi[0]=1;
    for(int i=1;i<2000005;i++){
        fact[i]=i*fact[i-1];
        fact[i]%=mod;
        modi[i]=power(fact[i],mod-2);
    }
}
 
ll ncr(ll n,ll r){
    if(n<r)
    return 0;
    ll ha=(((fact[n]*modi[n-r])%mod)*modi[r])%mod;
    return ha;
}

int main() {
	IOS;
	int t=1;
	pre();
	//cin>>t;
	while(t--){
		ll x,y;
		cin>>x>>y;
		ll a=0,b=2*x-y;
		if(b<0||b%3!=0){
			cout<<0;
			return 0;
		}
		b/=3;
		a=x-2*b;
		if(a<0){
			cout<<0;
			return 0;
		}
		cout<<ncr(a+b,a);
	}
	return 0;
}