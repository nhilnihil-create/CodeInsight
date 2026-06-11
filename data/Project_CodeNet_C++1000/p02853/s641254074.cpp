#include <bits/stdc++.h>
using namespace std;
//#include <atcoder/all>
//using namespace atcoder;
template <typename T> bool chmax(T &u, const T z) { if (u < z) {u = z; return true;} else return false; }
template <typename T> bool chmin(T &u, const T z) { if (u > z) {u = z; return true;} else return false; }
#define rep(i, n) for (long long i = 0; i < (long long)(n); i++)
#define ll long long
typedef pair<ll, ll> P;
const ll INF = 1LL << 60;
//const int MOD = 1000000007;
const ll MOD=998244353;
ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : x; }

int main(){
  int x,y;
  cin>>x>>y;
  int ans=0;
  if(x==1)ans=300000;
  else if(x==2)ans=200000;
  else if(x==3)ans=100000;
  if(y==1)ans+=300000;
  else if(y==2)ans+=200000;
  else if(y==3)ans+=100000;
  if(x==1&&y==1)ans+=400000;
  cout<<ans<<endl;
  return 0;
}