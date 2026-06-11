#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, a, b;
  cin >> n >> a >> b;
  long long x = 0;
  if (n % (a+b) > a) {
    x = a;
  }
  else {
    x = n%(a+b);
  }
  cout << n/(a+b)*a+x << endl;
}