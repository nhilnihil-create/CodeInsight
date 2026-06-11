#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define FOR(i, a, b) for (int i = a; i < (b + a); i++)
#define W1 while (1)
#define COUT(x) cout << x << endl
using namespace std;
using ll = long long;
using ld = long double;
#define ALL(x) x.begin(),x.end()
#define P pair<int,int>
#define mod 1000000007
#define PB push_back
#define F first
#define S second

int main() {
  int n;
  cin >> n;
  map<P, int> nset;
  FOR(i, 1, 9) {
    FOR(j, 1, 9) {
      nset[P(i, j)] = 0;
    }
  }
  FOR(i, 1, n) {
    int num = i;
    int fin = num % 10;
    if (fin == 0) continue;
    int init;
    W1 {
      if (num / 10 == 0) {
        init = num;
        break;
      }
      num /= 10;
    }
    nset[P(init, fin)]++;
  }
  ll ans = 0;
  FOR(i, 1, 9) {
    FOR(j, 1, 9) {
      ans += nset[P(i, j)] * nset[P(j, i)];
    }
  }
  COUT(ans);
  return 0;
}
