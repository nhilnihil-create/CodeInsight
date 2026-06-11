#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main()
{
  int n, q;
  cin >> n >> q;

  fenwick_tree<int64_t> fw(n);

  for (int i = 0; i < n; i++) {
    int64_t a;
    cin >> a;
    fw.add(i, a);
  }

  for (int i = 0; i < q; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a == 0) {
      fw.add(b, c);
    } else {
      cout << fw.sum(b, c) << endl;
    }
  }
}
