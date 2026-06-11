#pragma GCC optimize("O3")
#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
using P=pair<ll,ll>;
template<class T> using V=vector<T>; 
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
const ll inf=(1e18);
//const ll mod=998244353;
const ll mod=1000000007;
ll GCD(ll a,ll b) {return b ? GCD(b,a%b):a;}
ll LCM(ll c,ll d){return c/GCD(c,d)*d;}
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
vector<ll> divisor(ll n){
	vector<ll> ret;
	for(ll i=1;i<=(ll)sqrt(n);i++){
		if(n%i==0){
			ret.push_back(i);
            if(i*i!=n)ret.push_back(n/i);
		}
	}
	sort(ret.rbegin(),ret.rend());
	return(ret);
}
int main(){
	ll n,k;
	cin>>n>>k;
	V<ll> a(n);
	ll sum=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	V<ll> tmp=divisor(sum);
	for(ll v:tmp){
		V<ll> d(n),sum(n+1,0);
		for(int i=0;i<n;i++){
			d[i]=a[i]%v;
		}
		sort(all(d),greater<ll>());
		for(int i=0;i<n;i++){
			sum[i+1]=sum[i]+d[i];
		}
		ll res=0;
		ll times=inf;
		for(int i=0;i<=n;i++){
			if(res%v==(sum[n]-sum[i])%v){
			chmin(times,max(res,(sum[n]-sum[i])));
			}
			res+=(v-d[i])%v;
		}
		if(times<=k){
			cout<<v<<"\n";
			return 0;
		}
	}
}