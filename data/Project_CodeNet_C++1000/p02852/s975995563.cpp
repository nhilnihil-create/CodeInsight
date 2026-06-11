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
#define COUT(x) cout<<(x)<<endl
#define PQ priority_queue<ll>
#define PQR priority_queue<ll,vector<ll>,greater<ll>>
#define YES(n) cout << ((n) ? "YES" : "NO"  ) << endl
#define Yes(n) cout << ((n) ? "Yes" : "No"  ) << endl
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
using pll = pair<ll, ll>;
using vc = vector<char>;
using vvc = vector<vc>;
template<class T> inline bool chmax(T& a, T b) { 
 if (a < b) { a = b; return true; } return false; 
}
template<class T> inline bool chmin(T& a, T b) {
 if (a > b) { a = b; return true; } return false; 
}
ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
ll dx[4]={0,1,0,-1};
ll dy[4]={1,0,-1,0};
int main(){
  ll n,m;
  cin>>n>>m;
  string s;
  cin>>s;
  vll dp(n+1,INF);
  rep(i,n+1){
    if(s[i]=='0')dp[i]=-1;
  }
  multiset<ll> se;
  dp[0]=0;
  se.insert(0);
  rep(i,n+1){
    if(i==0) continue;
    if(dp[i]==INF){
      se.insert(INF);
      if(i>=m){
        se.erase(se.find(dp[i-m]));
      }
      continue;
    }
    if(*begin(se)==INF){
      COUT(-1);
      return 0;
    }
    dp[i]=*begin(se)+1;
    se.insert(dp[i]);
    if(i>=m){
      se.erase(se.find(dp[i-m]));
    }
  }
  vll ans(0);
  ll cu=dp[n];
  ans.pb(n);
  cu--;
  ll now=n;
  while(cu){
    ll co;
    rep(i,min(now,m)){
      if(cu==dp[now-i-1]){
        co=now-i-1;
      }
    }
    ans.pb(co);
    now=co;
    cu--;
  }
  ans.pb(0);
  reverse(all(ans));
  rep(i,sz(ans)-1){
    cout<<ans[i+1]-ans[i]<<" ";
  }
}