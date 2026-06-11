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
  string S,T; cin>>S>>T;
  string ans=""; rep(i,N) ans+="  ";
  for(int i=0;i<2*N;i+=2) ans[i]=S[i/2];
  for(int i=1;i<2*N;i+=2) ans[i]=T[i/2];
  cout<<ans<<endl;
  return 0;
}
