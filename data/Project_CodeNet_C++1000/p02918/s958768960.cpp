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
  int N, K;
  cin >> N >> K;
  string S;
  cin >> S;
  char key = S[0];
  int count = 0;
  rep(i, S.size()) {
    if(i == 0) continue;
    if(key == S[i]) {
      continue;
    } else {
      if(key == 'L') key = 'R';
      else key = 'L';
      count++;
    }
  }
  count++;

  int m = count - 2 * K;
  if(m <= 0) m = 1;
  int ans = N - m;
  cout << ans << endl;
  return 0;
}