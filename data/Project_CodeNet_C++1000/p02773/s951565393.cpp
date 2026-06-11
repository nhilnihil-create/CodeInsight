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
  cin >> N;
  string s[200000];
  map<string, int> mp;
  rep(i, N) {
    string temp;
    cin >> temp;
    s[i] = temp;
    mp[temp]++;
  }
  int m = 0;
  rep(i, N) {
    string temp = s[i];
    m = max(m, mp[temp]);
  }
  vector<string> v;
  rep(i, N) {
    string temp = s[i];
    if(mp[temp] == m) {
      v.push_back(temp);
      mp[temp] = 0;
    }
  }
  sort(v.begin(), v.end());
  rep(i, v.size()) {
    cout << v[i] << endl;
  }
  return 0;
}