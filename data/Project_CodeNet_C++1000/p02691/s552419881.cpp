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
  vector<ll> A(N); rep(i,N) cin>>A[i];
  
  vector<ll> vec(0);
  rep(i,N) vec.push_back(i-A[i]);
  sort(vec.begin(),vec.end());
  
  ll ans=0;
  rep(i,N){
    
    ll ok=N,ng=-1,low,up;
    while(abs(ok-ng)>1){
      ll mid=(ok+ng)/2;
      if(A[i]+i<=vec[mid]) ok=mid;
      else ng=mid;
    }
    low=ok;
    
    ok=N,ng=-1;
    while(abs(ok-ng)>1){
      ll mid=(ok+ng)/2;
      if(A[i]+i<vec[mid]) ok=mid;
      else ng=mid;
    }
    up=ok;
    
    ans+=up-low;
  }
  
  cout<<ans<<endl;
  return 0;
}