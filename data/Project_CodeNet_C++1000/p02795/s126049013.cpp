#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  int A, B, C;
  cin >> A >> B >> C;
  int X = max(A, B);
  int Y = min(A, B);
  int Z = 0;
  int c = 0;
  rep(i, Y) {
    c++;
    Z += X;
    if(Z >= C) {
      break;
    }
  }
  cout << c << endl;
}
    