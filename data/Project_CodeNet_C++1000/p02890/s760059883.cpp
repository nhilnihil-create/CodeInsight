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

int main()
{
  int n;
  cin>>n;
  vecint a(n);
  for(auto&& e:a) cin>>e;
  vecint b(n+1);
  for(auto&& e:a) {
    ++b[e];
  }
  boost::sort(b);
  vecint ps(n+1);
  boost::partial_sum(b, begin(ps));
  vecint num(n+1);
  int j = 0;
  for(auto&& i:irange(1,n+1)) {
    while (j <= n && b[j] <= i) ++j;
    int sum = ps[j-1] + (n+1-j) * i;
    num[i] = sum / i;
  }
  vecint res(n+1);
  for(auto&& i:irange(0,n+1)) {
    res[num[i]] = i;
  }
  for(int i=n-1; i>=0; --i) {
    res[i] = max(res[i], res[i+1]);
  }
  for(auto&& i:irange(1,n+1)) {
    cout<<res[i]<<endl;
  }
  return 0;
}
