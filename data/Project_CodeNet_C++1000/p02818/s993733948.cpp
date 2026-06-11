#include <bits/stdc++.h>
using namespace std;
int main() {
long long a,b,k;
  cin >> a >> b >> k;
  long long x = min(a,k);
  a -= x;
  k -= x;
  b -= min(b,k);
  cout << a <<" " <<b << endl;
  
}