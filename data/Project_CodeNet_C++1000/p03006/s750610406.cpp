#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define cinf(n,x) for(int i=0;i<(n);i++)cin>>x[i];
#define max3(a,b,c) max(max(a,b),c)
#define min3(a,b,c) min(min(a,b),c)
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

const ll INF=1000000000000000000;

signed main(){
    ll n;
    cin>>n;
    V<ll> x(n),y(n);
    rep(i,n) cin>>x[i]>>y[i];
    map<P,P> mp;
    map<P,ll> mm;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            if(i==j) continue;
            mp[P(i,j)]=P(x[i]-x[j],y[i]-y[j]);
            mm[P(x[i]-x[j],y[i]-y[j])]++;
        }
    }
    ll cnt=0;
    for(auto p:mm) chmax(cnt,p.sc);
    cout<<n-cnt<<endl;
}