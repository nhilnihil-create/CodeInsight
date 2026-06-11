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
ll powmod(ll n, ll k, ll m) {
ll r=1;
 for(; k>0; k >>=1) {
   if(k&1) r=(r*n)%m;
   n=(n*n)%m;
 }
  return r;
}

ll fact(ll n) {
ll a=1;
rep(i,n) {
a=a*(n-i);
}
return a;
}

ll pow(ll a, ll b) {
ll x=1;
rep(i,b) {
x=x*a;
}
return x;
}

int main() {
ll X;
  cin >>X;
  bool dp[1000000];
  dp[0]=true;
  repl(i,1,100) {
dp[i]=false;
  }

  dp[100]=true;
  dp[101]=true;
  dp[102]=true;
  dp[103]=true;
  dp[104]=true;
  dp[105]=true;
  
repl(i,106,1000000) {
  if((dp[i-100]) ||(dp[i-105])||(dp[i-101])||(dp[i-102])||(dp[i-103])||(dp[i-104])) {
    dp[i]=true;
  }
  else {
dp[i]=false;
  }
}
  
  
  
  if(dp[X]) {
    cout<<1<<endl;
  }
else {
cout<<0<<endl;
}

  
  
}