#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pcc pair<char,char>
#define vi vector <int>
#define vl vector <ll>
#define sd(x) scanf("%d",&x)
#define slld(x) scanf("%lld",&x)
#define pd(x) printf("%d",x)
#define plld(x) printf("%lld",x)
#define pds(x) printf("%d ",x)
#define pllds(x) printf("%lld ",x)
#define pdn(x) printf("%d\n",x)
#define plldn(x) printf("%lld\n",x)
#define INF 2e9
#define INFLL 4e18
using namespace std;
ll powmod(ll base,ll exponent,ll mod){ // with mod < 1e9
	ll ans=1;
	while(exponent){
		if(exponent&1)ans=(ans*base)%mod;
		base=(base*base)%mod;
		exponent/=2;
	}
	return ans;
}
ll gcd(ll a, ll b){
	if(b==0) return a;
	else return gcd(b,a%b);
}
const int upperlimit = 2e5+1;
const int mod = 1e9+7;
ll arr[upperlimit];
ll gaussian[65];
int lg(ll n){
	ll x=1;int ans=-1;
	while(x<=n){
		x*=2;
		ans++;
	}
	return ans;
}
int main() {
	ll ans=0,temp=0;
	int n;
	sd(n);
	for(int i = 1; i <= n; i++){
		slld(arr[i]);
		ans^=arr[i];
	}
	for(int i = 1; i <= n; i++) arr[i]-=(ans&arr[i]);
	for(int i = 1; i <= n; i++){
		for(int j = 63; j >= 0; j--) if((arr[i]^gaussian[j])<arr[i]) arr[i]^=gaussian[j];
		if(arr[i]) gaussian[lg(arr[i])]=arr[i];
	}
	for(int j = 63; j >= 0; j--) if((temp^gaussian[j])>temp) temp^=gaussian[j];
	temp*=2;
	ans+=temp;
	plld(ans);
	return 0;
}