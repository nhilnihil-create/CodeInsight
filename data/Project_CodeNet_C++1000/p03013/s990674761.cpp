#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n);i++)
using ll = long long;
const ll MOD=1000000007;
const long long INF = 1LL << 60;
const double pi=acos(-1.0);

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

vector<ll> table;
vector<bool> kaidan;

ll dp(ll n)
{
  if(kaidan.at(n)) return 0;
  if(n==0) return 1;
  if(n==1) return 1;
  if(table.at(n)>-1) return table.at(n);
  
  table.at(n)=(dp(n-1)+dp(n-2))%MOD;
  
  return table.at(n);
}  

int main() 
{
  ll N,M; cin>>N>>M;
  kaidan=vector<bool>(N+1,false);
  rep(i,M)
  {
    ll a; cin>>a;
    kaidan.at(a)=true;
  }
  table=vector<ll>(N+1,-1);
  cout<<dp(N)<<endl;
  /*
  rep(i,N+1)
  {
    if(i!=0) cout<<" ";
    cout<<kaidan.at(i);
  }
  */
  cout<<endl;
  return 0;
}