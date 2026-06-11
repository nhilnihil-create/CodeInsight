#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
constexpr int INF = 2e9;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> ac(n, 0), wa(n, 0);
  while (m--) {
    int p;
    string s;
    cin >> p >> s;
    p--;
    if (s == "WA") {
      if (!ac[p]) wa[p]++;
    } else {
      ac[p] = 1;
    }
  }
  int a = 0, b = 0;
  for (int i = 0; i < n; i++) {
    if (!ac[i]) continue;
    a++;
    b += wa[i];
  }
  cout << a << " " << b << endl;
  return 0;
} 