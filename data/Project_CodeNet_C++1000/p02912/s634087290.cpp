#include <functional>
#include <iostream>
#include <numeric>
#include <set>

using namespace std;
using ll = long long;

int main() {
  ll N, M, x;
  cin >> N >> M;
  multiset<ll, greater<>> s;
  for (int i = 0; i != N; ++i) {
    cin >> x;
    s.insert(x);
  }
  for (int i = 0; i != M; ++i) {
    ll a = *begin(s);
    s.erase(begin(s));
    s.insert(a/2);
  }

  cout << accumulate(begin(s),end(s),0ll) << endl;
}
