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



int main()
{
  ll N; cin>>N;
  vector<string> s(N);
  vector<ll> t(N); rep(i,N) cin>>s[i]>>t[i];
  string X; cin>>X;
  
  ll ans=0;
  int judge=0;
  rep(i,N){
    if(judge) ans+=t[i];
    if(s[i]==X) judge=1;
  }
  
  cout<<ans<<endl;
  return 0;
}