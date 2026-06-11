#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int main(void) {
  ll X, Y, A, B, C;
  cin >> X >> Y >> A >> B >> C;
  vector<ll> p(A), q(B), r(C);
  for (ll i = 0; i < A; i++) cin >> p[i];
  for (ll i = 0; i < B; i++) cin >> q[i];
  for (ll i = 0; i < C; i++) cin >> r[i];
  sort(p.rbegin(), p.rend());
  sort(q.rbegin(), q.rend());
  sort(r.rbegin(), r.rend());
  p.erase(p.begin() + X, p.end());
  q.erase(q.begin() + Y, q.end());
  p.insert(p.end(), q.begin(), q.end());
  p.insert(p.end(), r.begin(), r.end());
  sort(p.rbegin(), p.rend());
  ll sum = 0;
  for (ll i = 0; i < X + Y; i++) sum += p[i];
  cout << sum << endl;
  return 0;
}