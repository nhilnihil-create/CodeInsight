#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define repr(i,n) for(int i=n-1;i>=0;i--)
#define MAX(a,b) a=a>b?a:b
#define MIN(a,b) a=a<b?a:b
#define REP(i,x,n) for(int i=x;i<n;i++)
#define REPR(i,x,n) for(int i=n-1;i>=x;i--)
#define pb  push_back
#define ALL(obj) (obj).begin(), (obj).end()
#define ALLr(obj) (obj).rbegin(), (obj).rend()
#define endl "\n"
#define F first
#define S second
#define EN cout<<endl;
using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll,ll,ll> PP;
typedef tuple<ll,ll,ll,ll> PPP;
const ll mod=1000000007;
template<class T> void out(T a){cout<<a<<'\n';}
template<class T> void outp(T a){cout<<'('<<a.fi<<','<<a.se<<')'<<'\n';}
template<class T> void outvp(T v){rep(i,v.size())cout<<'('<<v[i].fi<<','<<v[i].se<<')';cout<<'\n';}
template<class T> void outvvp(T v){rep(i,v.size())outvp(v[i]);}
template<class T> void outv(T v){rep(i,v.size()){if(i)cout<<' ';cout<<v[i];}cout<<'\n';}
template<class T> void outvv(T v){rep(i,v.size())outv(v[i]);}
template<class T> bool isin(T x,T l,T r){return (l)<=(x)&&(x)<=(r);}
template<class T> void yes(T b){if(b)out("yes");else out("no");}
template<class T> void Yes(T b){if(b)out("Yes");else out("No");}
template<class T> void YES(T b){if(b)out("YES");else out("NO");}
template<class T> void no(T b){if(b)out("no");else out("yes");}
template<class T> void No(T b){if(b)out("No");else out("Yes");}
template<class T> void NO(T b){if(b)out("NO");else out("YES");}
ll gcd(ll a,ll b){if(b==0)return a;return gcd(b,a%b);}
ll modpow(ll a,ll b){ll res=1;a%=mod;while(b){if(b&1)res=res*a%mod;a=a*a%mod;b>>=1;}return res;}
 


int main(){
    ll n;
    cin>>n;
    ll ans[201010]={};
    ll a[201010]={};
    ll xo=0;
    rep(i,n){
        cin>>a[i];
        xo=xo^a[i];
        //cout<<xo;
    }
    rep(i,n){
        cout<<(a[i]^xo)<<" ";
    }
    //cout<<(0^20)<<endl;
    EN;


    
}
