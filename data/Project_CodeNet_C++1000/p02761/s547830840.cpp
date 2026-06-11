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
  int N, M;
  cin >> N >> M;
  int a[3];
  rep(i, 3) {
    a[i] = -1;
  }
  rep(i, M) {
    int s, c;
    cin >> s >> c;
    s--;
    if(s == 0) {
      if(N != 1 && c == 0) {
        cout << -1 << endl;
        return 0;
      }
    }
    if(a[s] == -1) {
      a[s] = c;
    } else if(a[s] != c) {
      cout << -1 << endl;
      return 0;
    }
  }
  rep(i, N) {
    if(i == 0) {
      if(a[i] == -1) {
        if(N == 1) a[i] = 0;
        else a[i] = 1;
      }
    } else {
      if(a[i] == -1) {
        a[i] = 0;
      }
    }
  }
  rep(i, N) {
    cout << a[i];
  }
  cout << endl;
  return 0;
}