#include <bits/stdc++.h>
using namespace std;
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define watch(x) cout << (#x) << " is " << (x) << endl
#define f(t) for(ll i=0;i<t;i++)
#define ll long long int
#define ld long double
#define umpl unordered_map<ll,ll> 
#define vl vector<ll>
#define vld vector<ld>
#define vvl vector<vl>
#define pb push_back
#define pll pair<ll,ll>
#define inf 1e18
#define pcout(x,p) cout<<fixed<<setprecision(p)<<x
#define all(a) a.begin(),a.end()
#define endl "\n"
const ll mod=1e9+7;
inline ll mul(ll a, ll b){ return (a * 1ll * b) % mod; }
inline ll sub(ll a, ll b){ ll c = a - b; if(c < 0) c += mod; return c; }
inline ll add(ll a, ll b){ ll c = a + b; if(c >= mod) c -= mod; return c; }
inline ll max(ll a, ll b){return a>b?a:b;}
inline ll min(ll a, ll b){return a<b?a:b;}
inline ll ceil(ll a,ll b){if(a%b==0)return a/b;else return a/b+1;}
inline ll mo(ll a,ll b){if(b<0){b=abs(b)%mod;b=a-b;return (b<0)?b+mod:b;}else{return (a+b)%mod;}}
inline ll pow(ll a,ll b){if(b==0){return 1;}else{if(b%2==0){ll temp=pow(a,b/2);return temp*temp;}
else{return a*pow(a,b-1);}}}

struct comp { 
    template<class T1,class T2,class T3,class T4>
    bool operator()(const pair<T1,T2> &p1,const pair<T3,T4> &p2){
        return p1.first<p2.first;
    }
};

int main(){
	ll n;cin>>n;
	vl a(n);
	f(n)cin>>a[i];
	ll ans=1000;
	for(ll i=1;i<n;i++){
		if(a[i]>a[i-1]){
			ans+=(a[i]-a[i-1])*(ans/a[i-1]);
		}
	}
	cout<<ans<<endl;
}