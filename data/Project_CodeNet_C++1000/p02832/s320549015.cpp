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
  vector<ll> a(N); rep(i,N) cin>>a[i];
  
  ll count=1;
  rep(i,N){
    if(a[i]==count) count++;
  }
  if(count==1) {cout<<-1<<endl; return 0;}
  else cout<<N-(count-1)<<endl;
  return 0;
}
