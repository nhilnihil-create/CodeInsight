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
#define md 1000000007
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
 
#define M 100010

int main(){
    
    ll h1,m1,h2,m2,k;
    cin>>h1>>m1;
    cin>>h2>>m2;
    cin>>k;
    ll ans=0;
    if(h1==h2)ans=m2-m1;
    else {
    	if(m1)ans+=(60-m1),h1++;
    	if(m2)ans+=m2;
    	ans+=60*(h2-h1);
    }
    cout<<max(0ll,ans-k);
    
    return 0;
}