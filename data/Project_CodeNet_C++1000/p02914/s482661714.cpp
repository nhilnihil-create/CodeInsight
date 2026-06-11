#include <bits/stdc++.h>
#include <boost/range/algorithm.hpp>
#include <boost/range/numeric.hpp>
#include <boost/range/irange.hpp>
#include <boost/range/adaptor/indexed.hpp>
#include <boost/dynamic_bitset.hpp>

using namespace std;
using namespace boost::adaptors;
using ll = int64_t;
using vecint = vector<int>;
using vecll = vector<ll>;
using boost::irange;

int main()
{
  int n;
  cin>>n;
  using bs = boost::dynamic_bitset<>;
  vector<bs> vb(60, bs(n+1));
  for(auto& v : vb) v.set(n);
  vecint cnt(60);
  for(int i : irange(0, n)) {
    ll a;
    cin>>a;
    for (int j : irange(0, 60)) {
      if (a&1) {
        vb[j].set(i);
        ++cnt[j];
      }
      a >>= 1;
    }
  }
  vector<bs> vc;
  vecint indices;
  ll ans = 0;
  for(auto&& c : index(cnt)) {
    if (c.value() % 2) {
      ans |= 1l << c.index();
    } else if (vb[c.index()].count() > 1) {
      vc.push_back(vb[c.index()]);
      indices.push_back(c.index());
    }
  }
  boost::reverse(vc);
  boost::reverse(indices);
  vector<bs> use;
  for(int j : irange(0, (int)vc.size())) {
    vector<bs> tmp = use;
    tmp.push_back(vc[j]);
    int m = tmp.size();
    bool ok = true;
    for(auto&& k:irange(0,m)) {
      size_t mnffs = n+1;
      int mnffsi = -1;
      for(auto&& l:irange(k,m)) {
        auto ffs = tmp[l].find_first();
        if (ffs == bs::npos) {
          continue;
        }
        if (ffs < mnffs) {
          mnffs = ffs;
          mnffsi = l;
        }
      }
      if (mnffs == n+1) {
        break;
      }
      if (mnffs == n) {
        ok = false;
        break;
      }
      swap(tmp[k], tmp[mnffsi]);
      for(auto&& l:irange(k+1,m)) {
        auto ffs = tmp[l].find_first();
        if (ffs == bs::npos) {
          continue;
        }
        if (ffs == mnffs) {
          tmp[l] ^= tmp[k];
        }
      }
    }
    if (ok) {
      ans += 2l << indices[j];
      use.push_back(vc[j]);
    }
  }
  cout<<ans<<endl;
  return 0;
}
