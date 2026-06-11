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
  vector<int> a(3);
  string ans = "No";
  rep(i, 3) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  if ((a[0] == a[1] && a[1] != a[2]) || (a[0] != a[1] && a[1] == a[2])) {
    ans = "Yes";
  }
  COUT(ans);

  return 0;
}
