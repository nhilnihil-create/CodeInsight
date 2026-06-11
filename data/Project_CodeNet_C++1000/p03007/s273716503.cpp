#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i=ll(a);i<ll(b);i++)
#define irep(i,a,b) for(ll i=ll(a);i>=ll(b);i--)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
#define pb push_back
#define mp make_pair
#define F .first
#define S .second 
using ll=long long;
using ld=long double;
const ll INF = 1LL<<60;
const ll mod=1e9+7;
using namespace std;
ll GCD(ll a, ll b) { return b ? GCD(b, a%b) : a; }

ll a[110000];
vector<ll> ap,am;
vector<ll>x,y;
int main(){
    ll n,t,a1,a2,cnt=0;
    cin>>n;
    rep(i,0,n)cin>>a[i];
    sort(a,a+n);
    rep(i,0,n-1){
        if(a[i]<0)am.pb(a[i]);
        else ap.pb(a[i]);
    }
    if(am.empty()){a2=ap[0];cnt++;}
    else if(ap.empty()) {a1=am[am.size()-1];a2=am[0];cnt++;}
    else a2=am[0];
    a1=a[n-1];
    while(cnt<ap.size()){
        x.pb(a2),y.pb(ap[cnt]);
        a2-=ap[cnt];
        cnt++;
    }
    x.pb(a1),y.pb(a2);
    a1-=a2;
    cnt=1;
    
    while(cnt<am.size()){
        x.pb(a1),y.pb(am[cnt]);
        a1-=am[cnt];
        cnt++;
    }
    cout<<a1<<endl;
    rep(i,0,x.size())cout<<x[i]<<" "<<y[i]<<endl;

}