 #include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >>c;
  int d = a+b;
  int e = b+c;
  int f = c+a;
  if(d <= e && d <= f) cout << d << endl;
  else if(e <= d && e <= f ) cout << e << endl;
  else cout << f << endl;
}