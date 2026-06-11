#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  int A, B;
  cin >> A >> B;
  int X = 0;
  if(A == 1) {
    X += 300000;
  }
  if(A == 2) {
    X += 200000;
  }
  if(A == 3) {
    X += 100000;
  }
  if(B == 1) {
    X += 300000;
  }
  if(B == 2) {
    X += 200000;
  }
  if(B == 3) {
    X += 100000;
  }
  if(A == 1 && B == 1) {
    X += 400000;
  }
  cout << X << endl;
}