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
  int n;
  cin >> n;
  int ans;
  while(true) {
    int x = n;
    for(int i = 2; i * i <= n; i++) {
      if(x % i == 0) {
        x /= i;
      }
    }
    if(x == n) {
      ans = n;
      break;
    }
    n++;
  }
  cout << ans << endl;
  return 0;
}