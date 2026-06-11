#include<bits/stdc++.h>
#define LL long long
using namespace std;
int main () {
  LL X, Y;
  cin >> X >> Y;
  LL m = 1e9 + 7;
  if ((X + Y) % 3) {
    cout << 0 << endl;
    return 0;
  }
  LL N = (X + Y) / 3;
  X -= N;
  Y -= N;
  if (X < 0 || Y < 0) {
    cout << 0 << endl;
    return 0;
  }
  //cout << X << ' ' << Y << endl;
  LL kj = 1;
  if (X > Y) swap(X, Y);
  for (LL i = 1ll; i <= X; i ++) {
    kj *= i;
    kj %= m;
  }
  LL m_ = m;
  m_ -= 2ll;
  LL k = 2ll;
  LL a = 1ll;
  while (m_) {
    if (m_ % k) a *= kj;
    kj = kj * kj;
    kj %= m;
    a %= m;
    m_ /= k;
    //cout << kj << endl;
    if (a == 0) {
      cout << m_ << ' ' << kj << ' ' << 'B' << endl;
      break;
    }
  }
  if (a == 0) cout << 'n' << endl;
  for (LL i = X + Y; i > Y; i --) {
    a *= i;
    a %= m;
  }
  cout << a << endl;
}

