#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;


int main()
{
  int n;
  cin >> n;
  vector<int> p(n);
  rep(i, n)
  {
    cin >> p[i];
    p[i]--;
  }
  vector<int> idx(n);
  rep(i, n)
    idx[p[i]] = i;
  multiset<int> s;
  s.insert(-1);
  s.insert(-1);
  s.insert(n);
  s.insert(n);
  ll ans = 0;
  for (int i = n - 1; i >= 0; i--)
  {
    int id = idx[i];
    ll l1, l2, r1, r2;
    s.insert(id);
    auto itr = s.find(id);
    r1 = *++itr;
    r2 = *++itr - r1;
    r1 -= id;
    itr--;
    itr--;
    l1 = *--itr;
    l2 = *--itr;
    l2 = l1 - l2;
    l1 = id - l1;
    ll c = r1 * l2 + r2 * l1;
    ans += (r1 * l2 + r2 * l1) * (i + 1);
  }
  cout << ans << endl;
  return 0;
}