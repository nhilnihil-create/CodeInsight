#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  rep(i, n) cin >> a[i] >> b[i];

  vector<P> job(n);
  rep(i, n) job[i] = make_pair(b[i], a[i]);
  sort(job.begin(), job.end());
  ll s = 0;
  bool ok = true;
  rep(i, n) {
    s += job[i].second;
    if (s > job[i].first) ok = false;
  }
  if (ok) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}