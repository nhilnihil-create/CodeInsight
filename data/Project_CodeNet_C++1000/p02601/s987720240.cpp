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

ll pla(ll n,ll i)
{
  ll x = pow(3,i + 1),y = pow(3,i);
  return n % x / y;
}

int main() 
{
  ll A,B,C; cin>>A>>B>>C;
  ll K; cin>>K;
  
  if(A<B&&B<C) {cout<<"Yes"<<endl; return 0;}
  
  rep(i,pow(3,K))
  {
    vector<ll> vec={A,B,C};
    rep(j,K)
    {
      vec.at(pla(i,j))*=2;
      if(vec.at(0)<vec.at(1)&&vec.at(1)<vec.at(2)) {cout<<"Yes"<<endl; return 0;}
    }
  }
  cout<<"No"<<endl;
  return 0;
}
