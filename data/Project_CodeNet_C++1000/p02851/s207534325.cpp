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

signed main(){
    ll n,k;
    cin>>n>>k;
    V<ll> a(n),s(n+1,0);
    cinf(n,a);
    rep(i,n) s[i+1]=s[i]+a[i];
    map<ll,V<ll>> mp;
    for(ll i=0;i<=n;i++) mp[(s[i]-i)%k].push_back(i);
    ll ans=0;
    for(auto p:mp){
        ll m=p.sc.size();
        for(int i=0;i<p.sc.size();i++){
            ll now=p.sc[i];
            ll x=ub(all(p.sc),now+k-1)-p.sc.begin();
            ans+=x-i-1;
        }
    }
    cout<<ans<<endl;
}