#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <ctype.h>
#include <math.h>
#include <stack>
#include <string>
#include <string.h>
using namespace std;
const double PI = acos(-1.0);
const long mod = 1000000007;
const long INF = 1e9 + 1;

int n;
vector<vector<pair<int, int>>> v;

bool judge(int bit) {
  for(int i = 0; i < n; i++) {
    if(!(bit & (1 << i))) continue;
    for(pair<int,int> xy : v[i]) { 
      int x = xy.first;
      int y = xy.second;
      if(y == 1 && !(bit & (1 << x))) return false;
      if(y == 0 && (bit & (1 << x))) return false;
    }
  }
  return true;
}

int main() {
  cin >> n;
  v.resize(n);
  for(int i = 0; i < n; i++) {
    int a; cin >> a;
    v[i].resize(a);
    for(int j = 0; j < a; j++) {
      cin >> v[i][j].first >> v[i][j].second;
      v[i][j].first--;
    }
  }

  int res = 0;
  for(int bit = 0; bit < (1 << n); bit++) {
    if(judge(bit)) {
      int cnt = 0;
      for(int i = 0; i < n; i++) {
        if(bit & (1 << i)) cnt++;
      }
      res = max(res,cnt);
    }    
  }

  cout << res << endl;
}