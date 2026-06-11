#include <stdio.h>
#include <vector>
#include <set>
using namespace std;
typedef long long ll;

int main(void) {
  ll i, j, k, n, a;
  scanf("%lld", &n);
  multiset<ll> s;
  multiset<ll>::iterator it;
  for(i = 0; i < (1 << n); ++i) scanf("%lld", &a), s.insert(a);
  it = s.end();
  it--;
  vector<ll> vec;
  vec.push_back(*it);
  s.erase(it);
  for(i = 0; i < n; ++i) {
    for(j = 0; j < (1 << i); ++j) {
      it = s.lower_bound(vec[j]);
      if(it == s.begin()) {
        printf("No");
        return 0;
      }
      it--;
      vec.push_back(*it);
      s.erase(it);
    }
  }
  printf("Yes");
  return 0;
}