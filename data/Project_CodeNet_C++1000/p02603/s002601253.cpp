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
  vector<ll> A(N); 
  rep(i,N) cin>>A.at(i);
  
  ll ans=1000,kabu=0;
  
  rep(i,N){
    //cout<<ans<<" "<<kabu<<endl;
    if(i==0) {
      if(A.at(1)>A.at(0)) {kabu+=ans/A.at(0); ans%=A.at(0);} continue;
    }
    if(i==N-1){
      ans+=kabu*A.at(N-1); break;
    }  
    if(A.at(i-1)<=A.at(i)&&A.at(i)>A.at(i+1)) {ans+=kabu*A.at(i); kabu=0;}
    if(A.at(i-1)>=A.at(i)&&A.at(i)<A.at(i+1)) {kabu+=ans/A.at(i); ans%=A.at(i);}
  }  
  cout<<ans<<endl;
  return 0;
}
