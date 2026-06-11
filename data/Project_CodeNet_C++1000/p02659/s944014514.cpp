#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
  ll a, b, c, d;
  scanf("%lld%lld.%lld", &a, &b, &c);
  d = a * (b * 100 + c) / 100;
  cout << d << endl;
  return 0;
}
