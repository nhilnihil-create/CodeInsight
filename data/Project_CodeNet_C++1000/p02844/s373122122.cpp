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
  string S; cin>>S;
  
  ll ans=0;
  rep(i,1000){
    vector<ll> vec={i/100,i%100/10,i%10};
    ll next=0;
    rep(j,N){
      if(next==3) break;
      if(S[j]-'0'==vec[next]) next++;
    }
    if(next==3) ans++;
  }
  
  cout<<ans<<endl;
  return 0;
}