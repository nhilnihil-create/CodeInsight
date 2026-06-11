#include <bits/stdc++.h>

using namespace std;

#define ll long long
typedef complex<double> P;

void show(P p) {
  cout << p.real() << ' ' << p.imag() << endl;
}

void koch(P p1, P p2, int n) {
  if(n == 0) return;

  P s = p1 + (p2 - p1) * P(1.0 / 3, .0);
  P t = p1 + (p2 - p1) * P(2.0 / 3, .0);
  P u = s + (t - s) * P(0.5, sqrt(3)/2);

  koch(p1, s, n-1);
  show(s);

  koch(s, u, n-1);
  show(u);
  
  koch(u, t, n-1);
  show(t);

  koch(t, p2, n-1);
}

int main() {
  int n;
  cin >> n;

  cout << fixed;
  cout << setprecision(8);

  P p1(0.0, 0.0);
  P p2(100.0, 0.0);

  show(p1);
  koch(p1, p2, n);
  show(p2);
}