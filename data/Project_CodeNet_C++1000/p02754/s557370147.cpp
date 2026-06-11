#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n, a, b;
  cin >> n >> a >> b;
  long long c = n / (a + b);
  long long d = n % (a + b);
  long long blue = c * a;
  if(d < a) blue += d;
  else blue += a;
  cout << blue << endl;
}