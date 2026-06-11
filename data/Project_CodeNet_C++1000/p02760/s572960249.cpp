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

int main() {
  int a[3][3];
  int b[3][3] = {0};

  int N;
  rep(i, 3) {
    rep(j, 3) {
      cin >> a[i][j];
    }
  }
  cin >> N;
  rep(i, N) {
    int temp;
    cin >> temp;
    rep(j, 3) {
      rep(k, 3) {
        if(temp == a[j][k]) {
          b[j][k] = 1;
        }
      }
    }
  }
  bool f = false;
  rep(i, 3) {
    if(b[i][0] == 1 && b[i][1] == 1 && b[i][2] == 1) f = true;
  }
  rep(i, 3) {
    if(b[0][i] == 1 && b[1][i] == 1 && b[2][i] == 1) f = true;
  }
  if(b[0][0] == 1 && b[1][1] == 1 && b[2][2] == 1) f = true;
  if(b[0][2] == 1 && b[1][1] == 1 && b[2][0] == 1) f = true;
  // rep(i, 3) {
  //   rep(j, 3) {
  //     cout << b[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  if(f) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}