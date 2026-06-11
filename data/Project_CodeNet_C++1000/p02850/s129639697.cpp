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
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
ll dx[4]={0,1,0,-1};
ll dy[4]={1,0,-1,0};
int main(){
  ll n;
  cin>>n;
  map<pll,ll> ans;
  vector<vll> t(n,vll(0));
  vector<pll> p(n-1);
  rep(i,n-1){
    ll a,b;
    cin>>a>>b;
    a--;b--;
    t[a].pb(b);
    t[b].pb(a);
    p[i]=pll(min(a,b),max(a,b));
    ans[pll(min(a,b),max(a,b))]=INF;
  }
  vll ch(n,-1);
  ch[0]=0;
  queue<ll> que;
  que.pu(0);
  while(sz(que)){
    ll now=que.front();que.pop();
    ll color=1;
    for(auto p:t[now]){
      if(ans[pll(min(p,now),max(p,now))]!=INF) continue;
      if(color==ch[now]) color++;
      ans[pll(min(p,now),max(p,now))]=color;
      ch[p]=color;
      color++;
      que.pu(p);
    }
  }
  ll an=0;
  for(auto p:ans){
    chmax(an,p.S);
  }
  COUT(an);
  rep(i,n-1){
    COUT(ans[p[i]]);
  }
}