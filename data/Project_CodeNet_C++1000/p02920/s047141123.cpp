#include <assert.h>
#include <limits.h>
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <complex>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <unordered_map>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using ll = long long;
using P = std::pair<ll, ll>;

#define rep(i, a, b) for (ll(i) = (a); i < (b); i++)
#define all(i) i.begin(), i.end()
#define debug(i) std::cerr << "debug "<< i << std::endl

// const ll MOD = 998244353;
const ll MOD = 1e9 + 7;

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  //問題文中の添え字が0-indexか1-indexか確認!

  ll n;
  std::cin>>n;

  /*unusedはまだ生成してないスライム
    slimeは生成したスライム*/
  std::multiset<ll> unused,slime;
  rep(i,0,1<<n){
    ll s;
    std::cin>>s;
    unused.insert(s);
  }

  //unusedの最大値を最初のスライムにする
  slime.insert(*unused.rbegin());unused.erase(*unused.rbegin());

  //各秒を貪欲で考える
  rep(i,0,n){
    //この秒で生成するスライムを保管しておくtemp
    std::vector<ll> temp;

    //今いるスライム各々が生成できる最大のスライムを作る
    for(auto itr=slime.rbegin();itr!=slime.rend();itr++){
      auto itr2=unused.lower_bound(*itr);

      //自分より小さいスライムがいないならNo
      if(itr2==unused.begin()){
        std::cout<<"No";
        return 0;
      }
      itr2--;
      temp.push_back(*itr2);
      unused.erase(itr2);
    }

    rep(j,0,1<<i)slime.insert(temp[j]);
  }

  std::cout<<"Yes";

  return 0;
}
