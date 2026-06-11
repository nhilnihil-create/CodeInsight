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

//dfs
vector<ll> vec;

void dfs(ll n,ll S){
  vec.push_back(S);
  if(n>=9) return;
  int edge=S%10;
  
  ll mid=S*10+edge; dfs(n+1,mid);
  if(edge<9) {ll high=S*10+edge+1; dfs(n+1,high);}
  if(edge>0) {ll low=S*10+edge-1; dfs(n+1,low);}
}

int main()
{
  ll K; cin>>K;
  
  //dfs
  vec=vector<ll>(0);
  rep(i,9) dfs(0,i+1);
  
  sort(vec.begin(),vec.end());
  cout<<vec[K-1]<<endl;
  return 0;
}