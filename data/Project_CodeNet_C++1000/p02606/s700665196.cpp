#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int mul_max(int A, int B) {
  int C = 0;
  for(int i = 0; i < 10000; i++) {
    C += B;
    if(C > A) {
      break;
    }
  }
  return C - B;
}
int main() {
  int A, B, C;
  cin >> A >> B >> C;
  int X, Y;
  X = mul_max(A - 1, C) / C;
  Y = mul_max(B, C) / C;
  cout << Y - X << endl;
}
