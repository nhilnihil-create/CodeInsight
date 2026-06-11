#include <bits/stdc++.h>
#define rep(i,s,n) for (ll i = s; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n,m;
  cin >> n >> m;
  vector<int> cnt_wa(n+1,0);
  vector<int> status(n+1,0);
  int wa = 0,ac = 0;
  rep(i,0,m) {
    int p; string s;
    cin >> p >> s;
    if (s == "AC") {
      if (status[p] != 2) {
        status[p] = 2;
        ac++;
      }
    } else {
      if (status[p] != 2) {
        status[p] = 1;
        cnt_wa[p]++;
        wa++;
      }
    }
  }
  rep(i,1,n+1) {
    if (status[i] == 1) {
      wa -= cnt_wa[i];
    }
  }
  cout << ac << " " << wa << endl;
  return 0;
}
