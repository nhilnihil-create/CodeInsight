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
  long long X;
  cin >> X;
  long long tmp = 100;
  int cnt = 0;
  while(true) {
    long long p = tmp / 100;
    // tmp = floor(tmp);
    cnt++;
    if(tmp >= X - p) {
      cout << cnt << endl;
      break;
    }
    tmp += p;
  }
  return 0;
}