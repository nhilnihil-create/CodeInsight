#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
#include <algorithm> 
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
#define ll long long
#define rep(i,n) for (ll i = 0; i < (n); i++)
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
#define FORR(i,a,b)for(ll i=(a);i<=(b);i++)
#define repR(i,n) for(ll i=n;i>=0;i--)
#define all(v)(v).begin(),(v).end()
#define rall(v)(v).rbegin(),(v).rend()
#define F first
#define S second
#define pb push_back
#define pu push
#define COUT(x) cout<<(x)<<"\n"
#define PQ priority_queue<ll>
#define PQR priority_queue<ll,vector<ll>,greater<ll>>
#define YES(n) cout << ((n) ? "YES\n" : "NO\n"  )
#define Yes(n) cout << ((n) ? "Yes\n" : "No\n"  )
#define mp make_pair
#define sz(x) (ll)(x).size()
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll MOD = 1000000007LL;
const ll INF = 1LL << 60;
using vll = vector<ll>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vvll = vector<vll>;
using vstr = vector<string>;
using vc = vector<char>;
using vvc = vector<vc>;
template<class T> inline bool chmax(T& a, T b) { 
 if (a < b) { a = b; return true; } return false; 
}
template<class T> inline bool chmin(T& a, T b) {
 if (a > b) { a = b; return true; } return false; 
}
ll dx[4]={0,1,0,-1};
ll dy[4]={1,0,-1,0};
int main(){
  ll n,k;
  cin>>n>>k;
  vll p(n),c(n);
  rep(i,n){
    cin>>p[i];
    p[i]--;
  }
  rep(i,n) cin>>c[i];
  ll ans=-INF;
  rep(i,n){
    vll syc(0);
    ll cu=0;
    ll now=i;
    while(1){
      now=p[now];
      syc.pb(c[now]);
      cu+=c[now];
      if(i==now) break;
    }
    vll sycc(sz(syc)+1);
    sycc[0]=0;
    rep(j,sz(syc)){
      sycc[j+1]=syc[j]+sycc[j];
    }
    ll ccu=-INF;
    for(int j=1;j<=sz(syc);j++){
      if(k<j) continue;
      if(k-j>=sz(syc)){
        if(cu>0){
          chmax(ccu,sycc[j]+(k-j)/sz(syc)*cu);
        }
        else chmax(ccu,sycc[j]);
      }
      else{
        chmax(ccu,sycc[j]);
      }
    }
    chmax(ans,ccu);
  }
  COUT(ans);
}