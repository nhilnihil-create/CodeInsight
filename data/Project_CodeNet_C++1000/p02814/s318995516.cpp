#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef int64_t Int;

Int IntLCM(Int a, Int b, Int MAX) {
    Int c = a / __gcd(a,b) * b;
    if (c > MAX) return -1;
    else return c;
}


int main(){ 
  
  Int N, M;
  cin >> N >> M;
  vector<Int> a(N);
  rep(i,N) {
      cin >> a[i];
      a[i] /= 2;
  }

  Int LCM = a[0];

  rep1(i,N-1) {
      Int n = IntLCM(LCM,a[i],M);
      if (n == -1) {
          cout << 0 << endl;
          return 0;
      }
      else LCM = n;
  }

  bool flag = true;

  rep(i,N) {
      if ((LCM / a[i]) % 2 == 0) flag = false;
  }

  if (!flag) {
      cout << 0 << endl;
      return 0;
  }

  cout << (M / LCM) - (M / (2 * LCM)) << endl;





}
