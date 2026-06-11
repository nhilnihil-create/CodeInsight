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
  int n, m, tmp1;
  string tmp2;
  cin >> n >> m;
  vector<bool> acflg(n + 1, false);
  vector<int> wa(n + 1, 0);
  rep(i, m) {
    cin >> tmp1 >> tmp2;
    if (tmp2 == "AC") acflg[tmp1] = true;
    if (!acflg[tmp1]) {
      if (tmp2 == "WA") wa[tmp1]++;
    }
  }
  int acsum = 0;
  int wasum = 0;
  FOR(i, 1, n) {
    if (acflg[i]) {
      acsum++;
      wasum += wa[i];
    }
  }
  cout << acsum << " " << wasum << endl;

  return 0;
}
