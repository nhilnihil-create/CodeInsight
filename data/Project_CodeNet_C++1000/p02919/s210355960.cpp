#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <numeric>
#include <iomanip>
#include <set>
#include <string.h>

using namespace std;

typedef long long ll;

#define REP(i,n) for(ll (i)=0;(i)<(n);(i)++)
#define REP3(i,st,en) for(ll (i)=(st);(i)<(en);(i)++)

using P = pair<ll, ll>;
const int MOD = 1e9+7;
const ll INF = 1e+14;
const double PI = 3.14159265349;


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll N;
  cin >> N;
  vector<P> PP(N);
  REP(i,N) {
      ll pi;
      cin >> pi;
      PP[i] = P(pi,i);
  }
  sort(PP.begin(), PP.end(), [](auto const& lp, auto const& rp){
      return lp.first > rp.first;
  });
  

  ll ans = 0;
  multiset<ll> seen = {-1,-1,PP[0].second,N,N};
  REP3(i,1,PP.size()){
    ll val = PP[i].first;
    ll index = PP[i].second;

    auto itr = seen.upper_bound(index);
    ll r1 = *itr;
    ll r2 = *next(itr);
    ll l1 = *next(itr,-1);
    ll l2 = *next(itr,-2);  
    
    ans += ((l1-l2)*(r1-index) + (index-l1)*(r2-r1)) * val;
    seen.insert(index);
  }

  cout << ans << "\n";
  return 0;
}

// 区間内にxより大きいものが1つのみ
//
// 最初にxより大きいものが出てくるindex l1 r1
// 次にxより大きいものが出てくるindex l2 r2
// ans += ((r2-i)*(i-l1)+(r1-i)*(l2-i)) * x
// xはPを大きい順に見る
// indexをsetで管理してlower_bound,upper_boundでr1,r2,l1,l2を獲得すればlog(N)