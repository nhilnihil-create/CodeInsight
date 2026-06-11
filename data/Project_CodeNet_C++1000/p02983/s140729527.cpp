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
  long long L, R;
  cin >> L >> R;
  long long ans = 2019;
  long long key = L % 2019;
  if(key == 0) {
    cout << 0 << endl;
    return 0;
  } else {
    if(R >= L + (2019 - key)) {
      cout << 0 << endl;
      return 0;
    } else {
      for(long long i = L; i <= R; i++) {
        for(long long j = i + 1; j <= R; j++) {
          ans = min(ans, (i * j) % 2019);
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}