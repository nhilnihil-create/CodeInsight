//https://atcoder.jp/contests/ddcc2020-qual/tasks/ddcc2020_qual_d
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
int main() {
#if LOCAL&01
  std::ifstream in("./test/sample-1.in");
  //std::ifstream in("./input.txt");
  std::cin.rdbuf(in.rdbuf());
#else
  cin.tie(0);
  ios::sync_with_stdio(false);
#endif
  ll M; cin>>M;
  ll keta=0;
  ll sum=0;
  REP(i,M){
    ll d,c; cin>>d>>c;
    keta += c;
    sum += (d*c);
  }
  ll ans=keta-1+((sum-1)/9);
  cout<<ans<<endl;
  return 0;
}