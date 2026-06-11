#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (int)(n);i++)
using ll = long long;
const ll MOD=1000000007;
const long long INF = 1LL << 60;
const double pi=acos(-1.0);

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

vector<ll> A,B;
ll H,N;

//dp
vector<ll> table;
ll dp(ll i){
  if(i<=0) return 0;
  if(table[i]<INF) return table[i];
  
  ll ret=INF-1;
  rep(j,N) chmin(ret,dp(i-A[j])+B[j]);
  
  return table[i]=ret;
}

int main()
{
  cin>>H>>N;
  A=vector<ll>(N),B=vector<ll>(N); rep(i,N) cin>>A[i]>>B[i];
  
  //dp
  table=vector<ll>(H+1,INF);
  
  cout<<dp(H)<<endl;
  
  return 0;
}