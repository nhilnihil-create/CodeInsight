#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define cinf(n,x) for(int i=0;i<(n);i++)cin>>x[i];
#define ft first
#define sc second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(v) (v).begin(),(v).end()
#define mod 1000000007
using namespace std;
typedef long long ll;
template<class T> using V=vector<T>;
using Graph = vector<vector<int>>;
using P=pair<ll,ll>;
typedef unsigned long long ull;
typedef long double ldouble;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//V,P(大文字)使用不可
//乗算の際にオーバーフローに注意せよ！！（適切にmodをとれ）
//制約をよく読め！

const ll INF=1e18;

ll f(ll n){
    ll m=1;
    rep(i,n) m*=10;
    return m;
}

signed main(){
    int n,p;
    cin>>n>>p;
    string s;
    cin>>s;
    ll ans=0;
    if(p==2){
        rep(i,n){
            if((s[i]-'0')%2==0) ans+=(ll)i+1;
        }
    }else if(p==5){
        rep(i,n){
            if((s[i]-'0')%5==0) ans+=(ll)i+1;
        }
    }else{
        map<ll,ll> mp;
        ll cnt=0;
        ll x=1;
        for(ll i=n-1;i>=0;i--){
            cnt+=((ll)s[i]-'0')*x;
            cnt%=p;
            mp[cnt]++;
            x=(x*10)%p;
        }
        mp[0]++;
        for(auto p:mp){
            ans+=p.sc*(p.sc-1)/2;
        }
    }
    cout<<ans<<endl;
}