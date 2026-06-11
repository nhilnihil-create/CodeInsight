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



int main() 
{
  ll N; cin>>N;
  if(N%2==1) {cout<<0<<endl; return 0;}
  ll ans=0;
  ans+=N/10;
  N/=10;
  while(N>0)
  {
    ans+=N/5;
    N/=5;
  }  
  cout<<ans<<endl;
  return 0;
}
