#include <bits/stdc++.h>
using namespace std;

int main() {
  int p, q, r, pq, qr, rp;
  cin >> p >> q >> r;
  pq = p + q;
  qr = q + r;
  rp = r + p;
  cout << min(pq, min(qr, rp)) << endl;
}