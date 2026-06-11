#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i < (n); i++)
#define lower(s) transform(s.begin(), s.end(), s.begin(), ::tolower)
using namespace std;
using ll = long long;
int INF = 1001001001;

int main() {
  ll a, b, k;
  cin >> a >> b >> k;
  if(k > 0 && k <= a) {
    a -= k;
  } else if (k > a && k <=a+b) {
    b = a + b - k;
    a = 0;
  } else if (k > a + b) {
    a = b = 0;
  }
  printf("%lld %lld\n", a, b);
  return 0;
}