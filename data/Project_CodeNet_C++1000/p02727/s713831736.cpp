#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int x, y, A, B, C;
  cin >> x >> y >> A >> B >> C;
  vector<int> a(A), b(B), c(C);
  for (int i = 0; i < A; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < B; i++) {
    cin >> b[i];
  }
  for (int i = 0; i < C; i++) {
    cin >> c[i];
  }
  sort(a.rbegin(), a.rend());
  sort(b.rbegin(), b.rend());
  sort(c.rbegin(), c.rend());
  long long sumr = 0;
  long long sumg = 0;
  int posx = x - 1;
  int posy = y - 1;
  int posz = 0;
  for (int i = 0; i < x; i++) {
    sumr += a[i];
  }
  for (int i = 0; i < y; i++) {
    sumg += b[i];
  }
  long long ans = sumr + sumg;
  while (posx >= 0 && posy >= 0 && posz < C) {
    if (c[posz] <= a[posx] && c[posz] <= b[posy]) break;
    if (a[posx] <= b[posy]) {
      ans = ans - a[posx] + c[posz];
      posx--;
    } else {
      ans = ans - b[posy] + c[posz];
      posy--;
    }
    posz++;
  }
  while (posx >= 0 && posz < C && c[posz] > a[posx]) {
    ans = ans - a[posx] + c[posz];
    posx--;
    posz++;
  }
  while (posy >= 0 && posz < C && c[posz] > b[posy]) {
    ans = ans - b[posy] + c[posz];
    posy--;
    posz++;
  }
  cout << ans << '\n';
  return 0;
}
