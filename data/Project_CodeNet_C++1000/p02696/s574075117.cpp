#include <bits/stdc++.h>
using namespace std;

int main () {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int a;
  long long b, n;
  cin >> a >> b >> n;
  long long mn = min (n, b - 1);
  cout << a * mn / b << '\n';
  return 0;
}
