#include <bits/stdc++.h>
using namespace std;

int main() {
  int p, q, r, pq, qr, rp;
  cin >> p >> q >> r;
  cout << min(p + q, min(q + r, r + p)) << endl;
}