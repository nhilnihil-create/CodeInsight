#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> l_l;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<P> vp;
typedef vector<l_l> vpl;
#define pb push_back
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define rep(i,n) for(int i=0;i<(n);i++)
#define rrep(i,n) for(int i=1;i<=(n);i++)
const int INF=1001001000;
const int mINF=-1001001000;
const ll LINF=10100100100100100;
template<class T> inline bool chmin(T& a,T b){
if(a>b){
a=b;
return true;
}
return false;
}
template<class T> inline bool chmax(T& a,T b){
if(a<b){
a=b;
return true;
}
return false;
}
int main(){
    ll n,m;cin>>n>>m;
    ll l=1,r=n-1;
    vl v;
    while(l<r){
        if(l%2!=0)v.pb(l);
        else v.pb(r);
        l++;r--;
    }
    sort(v.begin(),v.end());
    vp ans(m);
    ll u=n/2;
    rep(i,m){
        ans[i]=P(u,u+v[i]);
        u--;
    }
    rep(i,m)cout<<ans[i].fi<<" "<<ans[i].se<<endl;
    return 0;
}