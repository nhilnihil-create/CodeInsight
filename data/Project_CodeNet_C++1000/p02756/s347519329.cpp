#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  string s;
  int q;
  cin >> s >> q;

  bool rev = false;
  string head, tail;

  while (q --> 0) {
    int t;
    cin >> t;

    if (t == 2) {
      int f;
      char c;
      cin >> f >> c;

      if (rev) {
        if (f == 1) tail += c;
        else head = c + head;
      } else {
        if (f == 1) head = c + head;
        else tail += c;
      }
    } else rev ^= 1;
  }

  if (rev) {
    reverse(head.begin(), head.end());
    reverse(tail.begin(), tail.end());
    reverse(s.begin(), s.end());

    cout << tail << s << head << '\n';
  } else cout << head << s <<  tail << '\n';

  return (0);
}
