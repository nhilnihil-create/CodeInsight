#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  int A;
  cin >> A;
  int B = 0;
  for(int i = 1800; i >= 400; i -= 200) {
    B++;
    if(i <= A) {
      cout << B << endl;
      break;
    }
  }
}
