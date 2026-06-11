#include <bits/stdc++.h>
#include <boost/range/algorithm.hpp>
#include <boost/range/numeric.hpp>
#include <boost/range/irange.hpp>
#include <boost/range/adaptor/indexed.hpp>

using namespace std;
using namespace boost::adaptors;
using namespace std::string_literals;
using ll = int64_t;
using vecint = vector<int>;
using vecll = vector<ll>;
using boost::irange;

int main() {
  ll k,q;
  cin>>k>>q;
  vecll d(k);
  for(auto&& e:d) cin>>e;
  for(auto&& i:irange(0l,q)) {
    ll n,x,m;
    cin>>n>>x>>m;
    --n;
    ll sum = 0;
    for(auto&& e:d) {
      sum += (e+m-1) % m + 1;
    }
    sum *= n / k;
    sum += x % m;
    ll rem = n % k;
    for(auto&& j:irange(0l,rem)) {
      sum += (d[j]+m-1) % m + 1;
    }
    cout<<n-sum/m<<'\n';
  }
  cout<<flush;
  return 0;
}
