#include <bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stdio.h>
#include<cstring>
#include<math.h>
#include<map>
#include<bitset>
#include<iomanip>
#include<queue>
#include<functional>
#include<stack>
#include<tuple>
#include<cassert>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
using P = pair<int, int>;

vector<P> v[15];

int main() {
  int N;
  cin >> N;
  rep(i, N) {
    int a;
    cin >> a;
    rep(j, a) {
      int x, y;
      cin >> x >> y;
      x--;
      v[i].push_back({x, y});
    }
  }

  int ans = 0;

  rep(bit, (1<<N)) {
    bool f = true;
    rep(i, N) {
      if(bit & (1<<i)) {
        rep(j, v[i].size()) {
          if(v[i][j].second == 0) {
            if(bit & (1<<(v[i][j].first))){
              f = false;
              break;
            }
          } else {
            if(!(bit & (1<<v[i][j].first))){
              f = false;
              break;
            }
          }
        }
      }
      if(!f) break;
    }
      if(f){
        ans = max(ans, __builtin_popcount(bit));
        // cout << bit << endl;
      } 
  }

  cout << ans << endl;

  return 0;
}