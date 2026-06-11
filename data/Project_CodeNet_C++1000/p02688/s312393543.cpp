#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> tmp(n);
  rep(i, k) {
    int d;
    cin >> d;
    rep(j, d) {
      int a;
      cin >> a;
      tmp.at(a-1) = 1;
    }
  }
  int cnt = 0;
  rep(i, n) {
    if(tmp.at(i) == 0) cnt++;
  }
  cout << cnt << endl;
  return 0;
}