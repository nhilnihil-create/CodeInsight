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
  vector<int> a(n);
  rep(i, n) {
    cin >> a[i];
  }
  string ans = "APPROVED";
  rep(i, n) {
    if (a[i] % 2 == 0 && (a[i] % 3 != 0 && a[i] % 5 != 0)) {
      ans = "DENIED";
      break;
    }
  }
  COUT(ans);

  return 0;
}
