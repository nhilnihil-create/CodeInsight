// lcmとかはg++ -std=c++17 default.cppみたいなかんじで
//vector<vector<ll>> piyo(tate,vector<ll> (yoko));

#include <bits/stdc++.h>
#define mod 1000000007
#define INF 1000000000
#define ll long long
#define ln cout<<endl;
#define Yes cout<<"Yes"<<endl;
#define No cout<<"No"<<endl;
#define double long double
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define rep(i,n) REP(i,0,n)
using namespace std;

int main() {
    cin.tie(0);
   	ios::sync_with_stdio(false);

    ll a,b,d,m,n,maxi=0,f=0,mini=INF,sum=0;
    string str,str2;
    //ll x;
    cin>>a>>b>>m;
    vector<ll> aa(a);
    vector<ll> bb(b);
    vector<ll> x(m);
    vector<ll> y(m);
    vector<ll> c(m);

    rep(i,a) cin>>aa[i];
    rep(i,b) cin>>bb[i];
    rep(i,m) cin>>x[i]>>y[i]>>c[i];
    mini=*min_element(aa.begin(),aa.end())+*min_element(bb.begin(),bb.end());
    rep(i,m) mini=min(mini,aa[x[i]-1]+bb[y[i]-1]-c[i]);
    cout<<mini<<endl;

  
    return 0;
}