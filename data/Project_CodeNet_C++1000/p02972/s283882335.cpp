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

int N;
int a[200001];
int b[200001] = {0};

int main() {
  cin >> N;
  rep(i, N) {
    cin >> a[i+1];
  }
  for(int i = N; i >= 1; i--) {
    int key = 0;
    for(int j = i; j <= N; j = j + i) {
      if(i == j) continue;
      key += b[j];
    }
    if(key % 2 != a[i]) b[i]++;
    else continue;
  }

  vector<int> v;
  rep(i, N) {
    if(b[i+1] != 0) {
      v.push_back(i+1);
    }
  }
  cout << v.size() << endl;
  rep(i, v.size()) {
    cout << v[i];
    if(i != v.size()-1) cout << " ";
    else cout << endl;
  }

  return 0;
}