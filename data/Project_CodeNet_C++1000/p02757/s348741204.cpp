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
    ll n,p;cin >> n >>p;
     string s;cin >> s;
    if(p==2){
        ll ans=0;
        rep(i,n){
            if((s[i]-'0')%2==0)ans+=i+1;
        }
        cout << ans <<endl;
    }
    else if(p==5){
        ll ans=0;
        rep(i,n){
            if((s[i]-'0')%5==0)ans+=i+1;
        }
        cout << ans <<endl;
    }
    else{
        ll pre=0;
        ll rem=1;
        map<ll,ll> mp;
        mp[0]++;
        per(i,n){
            pre+=((s[i]-'0')*rem)%p;
            pre%=p;
            mp[pre]++;
            rem=(rem*10)%p;
            //cout << pre <<endl;
        }
        ll ans=0;
        for(auto p:mp){
            ans+=p.se*(p.se-1)/2;
        }
        cout << ans <<endl;
    }
}