#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define repl(i,l,r) for(ll i=(l);i<(r);i++)
#define per(i,n) for(ll i=n-1;i>=0;i--)
#define perl(i,r,l) for(ll i=r-1;i>=l;i--)
#define fi first
#define se second
#define pb push_back
#define ins insert
#define pqueue(x) priority_queue<x,vector<x>,greater<x>>
#define all(x) (x).begin(),(x).end()
#define CST(x) cout<<fixed<<setprecision(x)
#define vtpl(x,y,z) vector<tuple<x,y,z>>
#define rev(x) reverse(x);
using ll=long long;
using vl=vector<ll>;
using vvl=vector<vector<ll>>;
using pl=pair<ll,ll>;
using vpl=vector<pl>;
using vvpl=vector<vpl>;
const ll MOD=1000000007;
const ll MOD9=998244353;
const int inf=1e9+10;
const ll INF=4e18;
const ll dy[8]={1,0,-1,0,1,1,-1,-1};
const ll dx[8]={0,-1,0,1,1,-1,1,-1};
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
} 
int main(){
    ll n;cin >> n;
    vl v(n);rep(i,n)cin >> v[i],v[i]--;
    vl pls(n);
    rep(i,n)pls[v[i]]=i+1;rev(all(pls));
    //rep(i,n)cout << pls[i] <<endl;
    set<ll> st;
    st.ins(0);
    st.ins(n+1);
    ll ans=0;
    rep(i,n){
        //st.ins(pls[i]);
        auto itr=st.lower_bound(pls[i]),itrr=itr;
        itr--;ll l=*itr;itr--;ll l2=*itr;
        ll r=*itrr;itrr++;ll r2=*itrr;
        //cout << l2 <<" " << l <<" " << r <<" " << r2 <<endl;
        if(l!=0){
            ans+=(n-i)*(l-l2)*(r-pls[i]);
        }
        if(r!=n+1){
            ans+=(n-i)*(r2-r)*(pls[i]-l);
        }
        //cout << ans <<endl;
        st.ins(pls[i]);
    }
    cout << ans <<endl;
}