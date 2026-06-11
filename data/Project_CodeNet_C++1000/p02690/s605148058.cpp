#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int inf{int(1e9)};
int main(void){
  int X;
  cin >> X;
  for (int a = 1; a < 1000; a++){
    ll a5 = 1;
    rep(i,5) a5 *= a;
    for (int b = -1000; b < 1000; b++){
      ll b5 = 1;
      rep(i,5) b5 *= b;
      if (a5 - b5 == X){
        cout << a << " "  << b << endl;
        return 0;
      }
    }
  }
  return 0;
}
