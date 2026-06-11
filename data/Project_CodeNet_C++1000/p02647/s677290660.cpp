#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define mk make_pair
#define fi first
#define se second
#define vll vector<ll>
#define pii pair<ll,ll>
#define vvll vector< vector<ll> >
#define pb push_back
#define sz(v) (ll)(v).size()
#define inf 1e18
#define md 1e9+7
#define all(v) (v).begin(),(v).end()
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define tel(a){cout<<a<<"\n";}
#define tell(a,b){cout<<a<<" | "<<b<<"\n";}
#define telll(a,b,c){cout<<a<<" | "<<b<<" | "<<c<<"\n";}
#define teln(v,n){cout<<"v- ";rep(o,0,n)cout<<v[o]<<" ";cout<<"\n";}
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
#define TRACE
 
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif


#define M 110


int main(){
    IOS;
 
 	
 	ll n,k;cin>>n>>k;
 	ll a[n+1]={0},b[n+2]={0};
 	rep(i,1,n+1)cin>>a[i];
 	while(k--){
 		rep(i,1,n+1)b[max(1ll,i-a[i])]++,b[min(n+1,i+a[i]+1)]--;
 		rep(i,1,n+1)b[i]+=b[i-1];
 		bool ok=0;
 		rep(i,1,n+1){
 			if(a[i]!=b[i])ok=1;
 			a[i]=b[i],b[i]=0;
 		}
 		if(!ok)break;
 	}
 	rep(i,1,n+1)cout<<a[i]<<" ";
 	return 0;
}