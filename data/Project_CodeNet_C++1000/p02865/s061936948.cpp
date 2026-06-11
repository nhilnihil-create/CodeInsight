#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  int A;
  cin >> A;
  if(A % 2 == 0) {
    cout << (A - 2) / 2 << endl;
  }
  else {
    cout << (A - 1) / 2 << endl;
  }
}