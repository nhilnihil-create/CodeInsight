#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
 
int main() {
  int n,k,s;
  cin >> n >> k >> s;
  if (s == 1e9) {
    rep(i,k) cout << s << ' ';
    rep(i,n-k) cout << 1 << ' ';
    cout << endl;
  } 
  else {
    rep(i,k) cout << s << ' ';
    rep(i,n-k) cout << s+1 << ' ';
    cout << endl;
  }
  return 0;
}