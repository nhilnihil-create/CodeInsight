#include <iostream>

using namespace std;

#ifndef ONLINE_JUDGE
  #include <fstream>
  #define cin fin
  #define cout fout
  ifstream fin ("test.in");
  ofstream fout ("test.out");
#endif

int p[11];
int n, m, q;
int a[60], b[60], c[60], d[60];

int f (int i, int fn) {
  if (i == n + 1) {
    int r = 0;
    /*for (int j = 1; j <= n; j++)
      cout << p[j] << ' ';*/
    for (int j = 1; j <= q; j++) {
      if (p[b[j]] - p[a[j]] == c[j])
        r += d[j];
    }
    //cout << r << endl;
    return r;
  }
  int r = 0;
  for (int j = fn; j <= m; j++) { //intram cu toate permutarile de lungime n cu valori de la 1 la m
    p[i] = j;
    r = max (r, f(i + 1, j));
  }
  return r;
}

int main() {
  cin >> n >> m >> q;
  for (int i = 1; i <= q; i++)
    cin >> a[i] >> b[i] >> c[i] >> d[i];
  /*for (int i = 0; i < q; i++) {
    a[i]--; b[i]--;
  }*/
  cout << f (1, 1) << endl;
  return 0;
}
