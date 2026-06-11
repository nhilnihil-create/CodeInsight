#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (int)(n);i++)
using ll = long long;
const ll MOD=1000000007;
//const ll MOD=998244353;
const long long INF = 1LL << 60;
const double pi=acos(-1.0);

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }



int main()
{
  ll S; cin>>S;
  ll MAX=1000000000;
  ll Y3=S/MAX,X3=S%MAX;
  if(X3>0) {Y3++; X3=MAX-X3;}
  vector<ll> vec={0,0,MAX,1,X3,Y3};
  
  rep(i,6){
    if(i!=0) cout<<" ";
    cout<<vec[i];
  }
  cout<<endl;
  
  //cout<<MAX*Y3-1*X3<<endl;
  return 0;
}