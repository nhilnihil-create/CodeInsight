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
  ll H,W,K; cin>>H>>W>>K;
  vector<string> grid(H); rep(i,H) cin>>grid.at(i);
  
  ll ans=0;
  rep(i,1<<H){
    rep(j,1<<W){
      
      ll count=0;
      rep(k,H){
        rep(l,W){
          if(!(i&(1<<k))&&!(j&(1<<l))&&grid.at(k).at(l)=='#') count++;
        }
      }
      if(count==K) ans++;
    }
  }
  
  cout<<ans<<endl;
  return 0;
}
