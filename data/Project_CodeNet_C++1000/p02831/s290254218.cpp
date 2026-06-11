#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

ll gcd(ll a, ll b) {
  if (a%b == 0) {
     return(b);
  } else {
    return(gcd(b, a%b));
  }
}

ll lcm(ll a, ll b) {
  return a * b / gcd(a, b);
}


int main() {
  ll a,b;
  cin >> a >> b;
  printf("%lld\n", lcm(a,b));
  return 0;
}
