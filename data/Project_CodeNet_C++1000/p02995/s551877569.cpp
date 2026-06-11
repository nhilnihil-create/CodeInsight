#include <bits/stdc++.h>
using namespace std;

int64_t cnt_div(int64_t a, int64_t b, int64_t n) {
  int64_t ma = b/n;
  int64_t mi = (a-1)/n+1;

  return ma-mi+1;
}

int main() {
  int64_t a,b,c,d;
  cin>>a>>b>>c>>d;

  int64_t lcm = c/__gcd(c,d)*d;

  int64_t sum = cnt_div(a,b,c) + cnt_div(a,b,d) - cnt_div(a,b,lcm);

  int64_t ans = b-a+1-sum;

  cout<<ans<<endl;


  return 0;
}