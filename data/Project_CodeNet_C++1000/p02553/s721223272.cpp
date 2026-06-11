#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  
  long long ans = -100000000000000;
  long long ac = (long long)a*c;
  long long ad = (long long)a*d;
  long long bc = (long long)b*c;
  long long bd = (long long)b*d;

  cout << max(max(ac, ad), max(bc, bd)) << endl;
}
