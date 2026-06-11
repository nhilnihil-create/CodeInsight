//https://atcoder.jp/contests/sumitrust2019/tasks/sumitb2019_e
#include <bits/stdc++.h>
#if LOCAL
#include "dump.hpp"
#else
#define dump(...)
#endif
using namespace std;
using ll=long long;
const ll LINF = 0x1fffffffffffffff;
#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
template<class T>bool chmax(T &a, const T &b) {if (a<b) { a=b; return 1; } return 0;}
template<class T>bool chmin(T &a, const T &b) {if (b<a) { a=b; return 1; } return 0;}
constexpr ll MOD=1e9+7;
int main() {
  ll N; cin>>N;
  vector<ll> an(N);
  for(auto&& a:an) cin>>a;
  vector<ll> num(3);
  ll ans=1;
  for(const auto& a:an){
    ll mul=0; //みつからないと0になる
    FOR(i,0,3){
      if(num[i]==a) ++mul;
    }
    FOR(i,0,3){
      if(num[i]==a) {
        ++num[i];
        break;
      }
    }
    ans *= mul;
    ans %= MOD;
  }
  cout<<ans<<endl;
  return 0;
}