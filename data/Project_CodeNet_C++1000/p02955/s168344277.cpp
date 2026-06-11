#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repr(i, n) for (int i = (n); i >= 0; --i)
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define FORR(i, m, n) for (int i = (m); i >= (n); --i)
#define equals(a, b) (fabs((a) - (b)) < EPS)
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const ll mod2 = 998244353;
const int INF = 1000000005;
const long double EPS = 1e-10;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  int sum = 0;
  rep(i, n) {
    cin >> a[i];
    sum += a[i];
  }

  vector<int> d;
  for (int i = 1; i * i <= sum; i++) {
    if (sum % i == 0) {
      d.push_back(i);
      d.push_back(sum / i);
    }
  }
  sort(d.begin(), d.end(), greater<int>());

  int n2 = d.size();
  rep(i, n2) {
    vector<int> r(n);
    int sumr = 0;
    rep(j, n) {
      r[j] = a[j] % d[i];
      sumr += r[j];
    }
    sort(r.begin(), r.end(), greater<int>());

    int cnt = 0;
    rep(j, sumr / d[i]) {
      cnt += d[i] - r[j];
    }
    if (cnt <= k) {
      cout << d[i] << endl;
      return 0;
    }
  }

  
  return 0;
}