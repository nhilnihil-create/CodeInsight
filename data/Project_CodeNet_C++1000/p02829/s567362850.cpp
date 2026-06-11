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
  vector<int> vec(4,0); rep(i,3) vec[i+1]=1;
  ll A,B; cin>>A>>B; vec[A]=0,vec[B]=0;
  rep(i,4) if(vec[i]) cout<<i<<endl;
  return 0;
}
