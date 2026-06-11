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
	sort(ret.begin(),ret.end(),greater<ll>());
	return(ret);
}
int main(){
 ll n,d;
 cin>>n>>d;
 V<ll> a(n);
 ll sum=0;
 for(int i=0;i<n;i++){
     cin>>a[i];
     sum+=a[i];
 }
 sort(all(a));
 V<ll> tmp=divisor(sum);
 for(int k=0;k<tmp.size();k++){
     V<ll> b(n);
     ll t;
     sum=0;
     for(int i=0;i<n;i++){
          b[i]=a[i]%tmp[k];
          sum+=a[i]%tmp[k];
     }
     if(sum%tmp[k]!=0)continue;
     sum/=tmp[k];
     sort(all(b));
     ll need=0;
     for(int i=n-1;i>=n-sum;i--){
         need+=(tmp[k]-b[i])%tmp[k];
     }
     if(need<=d){
         cout<<tmp[k]<<"\n";
         return 0;
     }
 }
}