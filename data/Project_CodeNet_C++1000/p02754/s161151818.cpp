#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll n, a, b, sum;
  cin >> n >> a >> b;
  
  sum = n/(a+b)*a;
  if (n%(a+b)-a >= 0) sum += a;
  else sum += n%(a+b);
  
  cout << sum << endl;
}