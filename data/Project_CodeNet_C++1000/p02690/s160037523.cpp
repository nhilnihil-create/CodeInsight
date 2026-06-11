#include<bits/stdc++.h>
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
using ll = long long;
using P = pair<int, int>;
using MATRIX = vector< vector<ll> >;

int main() {
  int X;
  cin >> X;
  int key = 1;
  while(true) {
    if(pow(key, 4) > X) {
      break;
    }
    key++;
  }

  rep(i, key+1) {
    rep(j, key+1) {
      if(pow(i, 5)-pow(j, 5) == X) {
        cout << i << " " << j << endl;
        return 0;
      }
    }
  }

  rep(i, 100) {
    rep(j, 100) {
      if(pow(i, 5) + pow(j, 5) == X) {
        cout << i << " " << -j << endl;
        return 0;
      }
    }
  }

  return 0;
}