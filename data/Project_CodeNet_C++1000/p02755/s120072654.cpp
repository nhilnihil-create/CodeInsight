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
  double A, B;
  cin >> A >> B;
  int dA = ceil(100 * A / 8);
  int dB = ceil(100 * B / 10);
  int uA = floor(100 * (A+1) / 8);
  int uB = floor(100 * (B+1) / 10);
  if(8 * uA == 100 * (A + 1)) {
    uA--;
  }
  uB--;
  int d = max(dA, dB);
  int u = min(uA, uB);
  if(d > u) {
    cout << -1 << endl;
    return 0;
  }
  cout << d << endl;
  return 0;
}