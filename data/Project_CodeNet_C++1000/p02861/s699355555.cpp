#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n)                    \
  for (int i = 0; i < (int)(n); i++) \
    ;

#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0

int main() {
  long n;
  cin >> n;

  vector<pair<ll, ll>> p(n);
  for (auto& x : p) {
    cin >> x.first >> x.second;
  }

  sort(p.begin(), p.end());

  double sum = 0;
  ll count = 0;
  do {
    double tmp = 0;
    for (long i = 0; i < n - 1; i++) {
      ll dx = p.at(i).first - p.at(i + 1).first;
      ll dy = p.at(i).second - p.at(i + 1).second;
      tmp += sqrt(dx * dx + dy * dy);
    }
    sum += tmp;
    count++;

  } while (next_permutation(p.begin(), p.end()));
  cout << std::fixed << std::setprecision(64) << sum / count << endl;
}
