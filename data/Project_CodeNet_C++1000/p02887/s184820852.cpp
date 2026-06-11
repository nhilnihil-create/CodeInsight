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
  int N;
  string s;
  cin >> N >> s;
  int ans = 1;
  char key = s[0];
  rep(i, s.size()) {
    if(i == 0) continue;
    if(s[i] == key) {
      continue;
    } else {
      ans++;
      key = s[i];
    }
  }

  cout << ans << endl;
  return 0;
}