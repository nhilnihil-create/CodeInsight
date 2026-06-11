#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  ll a;
  double b;
  cin >> a >> b;
  ll llb = b*100+0.1;
  a *= llb;
  a /= 100;
  cout << a << endl;
  return 0;
}
