// g++ .cpp && ./a.out
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef pair<int, int> p;
typedef long long ll;

const int mod = 1000000007;
const int inf = 1000000007;

int main() {
  ll x;
  cin >> x;
  int a = 0;
  int b = 0;
  for (ll i = 0; i < 1000; i++) {
    for (ll j = -1000; j < 1000; j++) {
      if (i * i * i * i * i - j * j * j * j * j == x) {
        //cout << i * i * i * i * i - j * j * j * j * j << endl;
        a = i;
        b = j;
        break;
      }
    }
    if (a && b) break;
  }
  cout << a << ' ' << b << endl;
}
