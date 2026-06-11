#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double Double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

// chmax, chmin
template <class T> inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T> inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}

void solve(long long X) {
    X -= 400;
    X /= 200;
    cout << 8 - X << endl;
}

int main() {
  long long X;
  scanf("%lld", &X);
  solve(X);
  return 0;
}
