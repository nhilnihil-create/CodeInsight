#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t N, A, B;
  cin >> N >> A >> B;
  
  int64_t amari, syou, ans;
  syou = N/(A+B);
  amari = N%(A+B);
  
  if(amari > A)ans = syou*A + A;
  else ans = syou * A + amari;
  
  cout << ans << endl;
}