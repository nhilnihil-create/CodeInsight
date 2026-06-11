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
const int mod = 1000000007;
const int max_n = 200005;
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
ll modpow(ll a, ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
int main(){
    ll n,p;cin >> n >>p;
    string s;cin >> s;
    if(p!=2&&p!=5){
        rev(all(s));
        vl v(s.size());
        ll tmp=0;
        rep(i,s.size()){
            tmp+=modpow(10,i,p)*(s[i]-'0');
            //cout << tmp <<endl;
            tmp%=p;
            v[i]=tmp;
        }
        //rep(i,s.size())cout << v[i] <<endl;
        vl count(p,0);
        count[0]++;
        rep(i,s.size())count[v[i]]++;
        ll ans=0;
        rep(i,p){
            ans+=count[i]*(count[i]-1)/2;
        }
        cout <<ans <<endl;
    }
    if(p==2){
        ll ans=0;
        rep(i,n){
            if((s[i]-'0')%2==0){
                ans+=i+1;
            }
        }
        cout <<ans <<endl;
    }
    if(p==5){
        ll ans=0;
        rep(i,n){
            if((s[i]-'0')%5==0){
                ans+=i+1;
            }
        }
        cout <<ans <<endl;
    }
}