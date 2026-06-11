#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
const double eps = 1e-10;
const int MOD = 1000000007;
const int INF = 1000000000;
const ll LINF = 1ll<<50;
template<typename T>
void printv(const vector<T>& s) {
  for(int i=0;i<(int)(s.size());++i) {
    cout << s[i];
    if(i == (int)(s.size())-1) cout << endl;
    else cout << " ";
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  int n; cin >> n;
  vector<ll> a(n), b(n);
  for(int i=0;i<n;++i) {
    cin >> a[i];
  }
  for(int i=0;i<n;++i) {
    cin >> b[i];
  }
  priority_queue<P> pq;
  for(int i=0;i<n;++i) {
    pq.push({b[i], i});
  }
  ll ans = 0;
  while(!pq.empty()) {
    P p = pq.top(); pq.pop();
    ll now = p.first, idx = p.second;
    if(now != b[idx]) continue;
    ll idx1 = (idx + n - 1) % n, idx2 = (idx + 1) % n;
    if((now - a[idx]) % (b[idx1] + b[idx2]) == 0) {
      if(now - a[idx] == 0) continue;
      ans += (now - a[idx]) / (b[idx1] + b[idx2]);
      b[idx] = a[idx];
      pq.push({b[idx], idx});
    } else {
      ll tmp = b[idx1] + b[idx2];
      if(tmp == 0) continue;
      ll cnt = (now - tmp - 1) / tmp + 1;
      ans += cnt;
      b[idx] -= cnt * tmp;
      if(b[idx] < 0) {
        cout << -1 << endl;
        return 0;
      }
      pq.push({b[idx], idx});
    }
  }
  bool ok = true;
  for(int i=0;i<n;++i) {
    ok &= a[i] == b[i];
  }
  cout << (ok ? ans : -1) << endl;
}
