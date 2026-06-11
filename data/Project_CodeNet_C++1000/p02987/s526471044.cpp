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
  string s;
  cin >> s;
  vector<char> v;
  map<char, int> mp;
  rep(i, 4) {
    if(mp[s[i]] == 0) {
      v.push_back(s[i]);
    }
    mp[s[i]]++;
  }
  if(v.size() != 2) cout << "No" << endl;
  else {
    bool f = true;
    rep(i, v.size()) {
      if(mp[v[i]] != 2) f = false;
    }
    if(f) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
  return 0;
}