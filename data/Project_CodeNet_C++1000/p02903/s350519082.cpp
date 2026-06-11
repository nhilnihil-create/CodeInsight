#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const ll Mod = 998244353;
const int MAX = 510000;
const double PI = 3.14159265358979;
const vector<int> dx = {1, 0};
const vector<int> dy = {0, 1};

int main() {
  int H, W, A, B;
  cin >> H >> W >> A >> B;
  if (H>1&&W>1) {
    for (int i=0; i<H; i++) {
      for (int j=0; j<W; j++) {
        if (i<B) {
          if (j<A) cout << 0;
          else if (j!=W-1) cout << 1;
          else cout << 1 << endl;
        }
        else {
          if (j<A) cout << 1;
          else if (j!=W-1) cout << 0;
          else cout << 0 << endl;
        }
      }
    }
  }
  else if (H==1&&W==1) cout << 0 << endl;
  else if (H==1) {
    for (int j=0; j<W; j++) {
      if (j<A) cout << 0;
      else if (j!=W-1) cout << 1;
      else cout << 1 << endl;
    }
  }
  else if (W==1) {
    for (int i=0; i<H; i++) {
      if (i<B) cout << 0 << endl;
      else cout << 1 << endl;
    }
  }
  return 0;
}